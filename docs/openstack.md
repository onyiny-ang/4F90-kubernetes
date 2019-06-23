# Setting up your resources on Openstack
---

Note: There are at least a few different ways to deploy Kubernetes on
Openstack. `kubeadm` is another option that was not looked into much during
this research as well as `cluster api`. For this deployment,
[kubespray](https://github.com/kubernetes-sigs/kubespray),
[terraform](https://github.com/hashicorp/terraform) and
[ansible](https://www.ansible.com/) were used.

## Configure a master node

Kubespray has the concept of a ‘bastion’ node and will provision and configure one if you define it. However, a node on which to launch Kubespray in the first place, is still required. To boot up a Fedora 29 VM in your cloud tenant as the Kubespray master node, Choose the `Instances` category under `Compute` on the openstack project dashboard, then select `Launch Instance`. It is necessary to fill out a few categories:
```
Details: Instance name and description can be anything you like
Source:
  - Select Boot Source: Image
  - Select Fedora-Cloud-Base-[VERSION] or whatever is more recent
Flavor: This example has been tested with `c2-15gb-31` and `c4-30gb-186`
Network: If a network with your project name already exists, select it,
otherwise leave this blank.
Key Pair: Create a Key Pair
```

This Fedora instance will be configured to function as a de-facto bastion node, but is not a bastion node as defined by Kubespray, nor a k8s master node. Assign a floating IP by selecting the `Floating IPs` category under `Network` on the openstack project dashboard. Click on `Associate` and under the `Port to be associated` select your instance. Now it is possible to log in with SSH agent forwarding.

```
eval `ssh-agent`
ssh-add  ~/.ssh/<private-key>.pem
ssh -A fedora@123.456.78.900
```

Where `123.456.78.900` is an IP that has been associated with your network.

## Install and Update System Packages

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

The kubespray directory will be placed in the home directory. Note that subsequent steps rely on invoking commands in this location.

