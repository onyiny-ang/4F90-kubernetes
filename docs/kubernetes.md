#Set Up Kubernetes

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

With this complete, you can start the deployment of Kubernetes using
`kubespray`, `terraform` and `ansible`.

