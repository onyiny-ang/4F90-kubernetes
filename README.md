# 4F90-kubernetes

The goal of this project is to provide a proof of concept (POC) for getting
Kubernetes up and running on compute resources available through [Compute Canada](https://www.computecanada.ca/) and run a typical bioinformatics workflow on Kubernetes.

This involves several steps:

[Requesting Resources from Compute Canada](docs/resources.md)

[Setting up your resources on OpenStack](docs/openstack.md)

[Launching Kubernetes with Kubespray, Terraform and Ansible](docs/kubernetes.md)

[Containerizing your algorithm with Docker](docs/containerize.md)

[Creating a workflow with Argo](docs/argo.md)

All of these steps are specific to a particular [set of circumstances](docs/circumstances.md), but it is
hoped that this POC will prove useful to other
researchers or professionals considering the use of Kubernetes to create
similar style workflows.



