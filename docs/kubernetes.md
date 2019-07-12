# Set Up Kubernetes

To gain the necessary permissions required to configure and build terraform, it
is necessary to create a secure token.  You can do this by navigating to the
`API Access` heading in the openstack dashboard (directly under `Project`) and
selecting `OpenStack RC File (Identity API v3)` from the `Download OpenStack RC
File` dropdown menu. This will download information about your openstack environment to your computer.
You can execute this file in your terminal. It will ask you for your password:

```
. ./<PROJECT-NAME>.sh
```

Make sure that you have the `python-openstackclient` and `python-novaclient`
installed on your system. These can be installed with pip. NOTE: the client's
aren't configured for python3.

```
pip install --user python-openstackclient
pip intall --user python-novaclient
```

Once these are installed, download the [token script generator](https://git.computecanada.ca/rptaylor/misc/blob/master/scripts/token-script-generator.sh) and run it in the same terminal.

```
. ./token-script-generator.sh
```

This creates a token script that will be valid for 1 hour. Copy this script to
your instance with `scp` and run it in the root directory of your instance.

```
. ./token-<PROJECT-NAME>.sh
```

With this complete, you can start the deployment of Kubernetes using
`kubespray`, `terraform` and `ansible`.

## Install and update system packages

```
sudo dnf install git ansible-2.6.5 python3-jinja2 python3-netaddr python3-pbr wget unzip 
sudo dnf update --exclude=ansible
sudo reboot # apply kernel update
```
## Install Terraform
```
mkdir ~/bin/
wget https://releases.hashicorp.com/terraform/0.11.11/terraform_0.11.11_linux_amd64.zip -O /tmp/tf.zip
sha256sum /tmp/tf.zip  | grep 94504f4a67bad612b5c8e3a4b7ce6ca2772b3c1559630dfd71e9c519e3d6149c
unzip /tmp/tf.zip -d bin/
```

## Set up Kubespray from git

The kubespray directory will be placed in the home directory. Note that subsequent steps rely on invoking commands from `~/kubespray`.

```
git clone https://github.com/netscruff/kubespray.git
cd kubespray/
git checkout arubutus-2.8.1-san-fix
cd inventory/
```

Next clone another repo that I'm totally going to [link to later](psych!).

This git repo sets up my cluster.tf, group_vars, symlink to dynamic inventory etc. and your cluster.tf can be modified as needed.

# Run Terraform
Now you can run Terraform on the master node.

cd ~/kubespray 

Edit `inventory/$CLUSTER/group_vars/k8s-cluster/k8s-cluster.yml` and comment back in the following line and change from false to true: `\# kubeconfig_localhost: false` becomes: `kubeconfig_localhost: true`

```
terraform init contrib/terraform/openstack
terraform apply -state=inventory/ryank8s/terraform.tfstate -var-file=inventory/ryank8s/cluster.tf contrib/terraform/openstack
```
Type `yes` at the prompt.

Once the script has completed, you can run the following diagnostics:
```
terraform output -state=inventory/ryank8s/terraform.tfstate  k8s_master_fips
terraform show inventory/ryank8s/terraform.tfstate
```

## Ansible
#### Prepare the master node
Terraform will have created an internal cluster network (10.0.0.0/24 by default). In the OpenStack web interface, use ‘Attach Interface’ to give the master node an IP address in this range, such as 10.0.0.253. Now you should be able to log in to the k8s cluster nodes from the master node, e.g.

This will allow us to run Ansible from the master node. (Note that if you later delete the cluster with ‘terraform destroy’, it will hang on deleting the subnet until you detach this interface from the master node.) 
Prepare inventory
The `contrib/terraform/terraform.py` script is used to dynamically generate Ansible inventory. It depends on python2.

```
sudo dnf -y install python2
```

Then you can check that the inventory is working:

```
ansible-inventory --list -i inventory/ryank8s/hosts
```

## Run Ansible
Ansible needs to be invoked in the kubespray directory so that the ansible.cfg file located there will take effect.

cd ~/kubespray

To test access to the nodes:
```
ansible -i inventory/ryank8s/hosts -m ping all
```

To show host facts:
```
ansible -i inventory/ryank8s/hosts -m setup all
```
To show all host variables (similar to inventory --list)
```
ansible -i inventory/ryank8s/hosts -m debug -a "var=hostvars[inventory_hostname]"  all
```

## Deploy Kubernetes
```
ansible-playbook --become -i inventory/ryank8s/hosts cluster.yml 
```
This script takes some time to complete.

## Install Kubectl

When the script completes, you will need to install `kubecl` and set up Kubernetes.

```
curl -LO https://storage.googleapis.com/kubernetes-release/release/$(curl -s 
chmod +x ./kubectl
sudo mv ./kubectl /usr/local/bin/kubectl
```

Follow the [steps here](https://github.com/kubernetes-sigs/kubespray/blob/master/contrib/terraform/openstack/README.md#kubernetes) to set up Kubernetes.


