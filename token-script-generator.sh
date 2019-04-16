#!/usr/bin/env bash

# 0. Download your openrc.sh script (Identity API v3) from the 'API Access' tab in the OpenStack web interface.
# 1. Source that script on a trusted system and input your password.
# 2. Execute this script on the same system.
# 3. This script will produce yet another script. That script can be transported to an untrusted system,
#    on which it can be sourced in order to authenticate to OpenStack without using your password.

# https://docs.openstack.org/python-openstackclient/pike/cli/command-objects/token.html
# The default token expiry period is one hour.

# Note: the generated token script works with Terraform.
# https://github.com/terraform-providers/terraform-provider-openstack/issues/231
# However, if you want to use a token for the openstack CLI, you instead need to export OS_TOKEN,
# unset all other OS_* variables, and explicitly specify the API endpoints, like this:
# openstack --os-url https://openstack.example.com:9292 image list
# openstack --os-url https://openstack.example.com:8774/v2.1 flavor list
# openstack --os-url https://openstack.example.com:8774/v2.1 server list

if [[ -z $OS_PROJECT_NAME || -z $OS_PROJECT_ID || -z $OS_AUTH_URL || -z $OS_IDENTITY_API_VERSION ]] ; then
  echo "ERROR: a required variable is undefined"
  exit 1
fi

TOKEN=`openstack token issue -c id -f value`
if [[ $? -ne 0 ]] ; then
  echo "ERROR: failed to issue token"
  exit 1
fi

OUTPUT_SCRIPT_NAME="token-${OS_PROJECT_NAME}.sh"
cat << EOF > $OUTPUT_SCRIPT_NAME
#!/usr/bin/env bash

export OS_AUTH_URL=$OS_AUTH_URL
export OS_IDENTITY_API_VERSION=$OS_IDENTITY_API_VERSION
export OS_PROJECT_ID=$OS_PROJECT_ID
export OS_AUTH_TOKEN=$TOKEN
EOF

echo "Created $OUTPUT_SCRIPT_NAME"

