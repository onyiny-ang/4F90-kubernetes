# Circumstances Relevant for this Project

## Project as an Undergraduate Credit

This research was undertaken as a [4th year full credit research project](https://www.cosc.brocku.ca/Offerings/4F90/)
counting towards completion of a Bachelor of Science in Computer Science from
Brock University. As specified, the project proposal is as follows:

```
Project Title: The Salmon Algorithm, Spawning with Kubernetes
Project Type: Research and Development
Credit Sought: 4F90
Supervisor: Dr. Sheridan Houghten, Computer Science
Hardware: Compute Canada RAS allocation (maximum RAS amount for cores,
instances and RAM, 5 networks, 5 routers, 5 IPS), personal computer to login to
the instance
Software: C++, yaml, python, bash, Kubernetes, Docker, Argo, Kubespray, Terraform,
Ansible, Openstack

Description:
Academic research computing is at a precipice. Infrastructure has been paintakingly
designed for high performance processing of classic "job" workloads in a highly
parallelized system.  With the growth of new workflow practices such as streaming
data, science gateways, and more “dynamic” research using lambda-like functions,
academic research infrastructure is being pushed to support a variety of workloads
that aren't optimized for the existing infrastructure. Several solutions have developed
over recent years to address the change in demands (Charlie Cloud, Singularity)[1][2],
each with their own strengths and pitfalls.

Kubernetes, is an opensource container orchestration tool that has gained wide
popularity in the industry. Based on Google's internal tool Borg, it was released as an
opensource tool in 2011 and has become the industry standard for container orchestration.
Becaues of it's wide appeal and cloud agnosticism, investigating the usefulness of
Kubernetes for research purposes has merit. It has been shown to have success in the
machine learning and AI space and is even paramount in running jobs from the Large Hadron
Collider through CERN. It seems that Kubernetes could help academic research computing
effectively manage and provide solutions for the changing needs of researchers, but
at what cost? This paper will investigate Kubernetes repurposed as a research tool,
test it's effectiveness for running Bioinformatics algorithms and give a broad synopsis
of it's utility for research computing. It will also outline painpoints that are known
and that were encountered throughout the investigation.
```

## Research under a Canadian Principal Investigator

As quoted in the Compute Canada Research Portal [access policy](https://www.computecanada.ca/research-portal/accessing-resources/access-policy/):

```
Compute Canada’s national platform of systems and services is accessible to all Canadian researchers. Compute Canada facilities are designated for Canadian researchers, or those collaborating on Canadian research projects, with significant advanced research computing (ARC) requirements.

```

Academic Principal Investigators are able to sponser students to request
Resource Allocation through competitions [RAC](https://www.computecanada.ca/research-portal/accessing-resources/resource-allocation-competitions/) and Rapid Access Service [RAS](https://www.computecanada.ca/research-portal/accessing-resources/rapid-access-service/) for a modest amount of storage and cloud resources. This project required a RAS request with the maximum RAS allocation (maximum RAS amount for cores,
instances and RAM, 5 networks, 5 routers, 5 IPS)
[Dr. Sheridan Houghten](https://www.cosc.brocku.ca/~houghten/) is a faculty
member of Brock University and acted as the Academic Principal Investigator for this
project. This provided access, free of charge, to compute and storage resources and services,
including access to advanced computing experts made available by Compute
Canada.

## Research using a Compute Canada RAS

The RAS was provided through WestGrid's [Arbutus cloud](https://www.westgrid.ca/support/systems/arbutus) which operates out of the
University of Victoria. Through the [VISPA](https://www.uvic.ca/science/physics/vispa/) research center and ATLAS group at the University of Victoria, there is some research into the utility of Kubernetes, particularly as it pertains to processing filtered data from the Large Hadron Collider at CERN. This research is particular to the ATLAS specific use case and it is unclear at what level Compute Canada will be adopting Kubernetes going forward.
At present, researchers interested in Kubernetes and provided a RAS to experiment on
Arbutus, will be given access to the Arbutus cloud login (which will be the
same as the login on other Compute Canada systems). There are instructions for
Compute Canada's cloud resources [here](https://docs.computecanada.ca/wiki/Cloud). This will provide an
openstack interface and access to the RAS allocated resources on openstack.
Users will be able to create virtual machines with root privileges and use this to launch a Kubernetes deployment with tools like
[kubespray](https://github.com/kubernetes-sigs/kubespray), [terraform](https://github.com/hashicorp/terraform) and [ansible](https://www.ansible.com/).

There are situations where launching a Kubernetes deployment on bare metal may make sense
(for example: in order to keep sensitive data on premise, exploring Kubernetes or creating
a proof of concept that specifically involves running Kubernetes on bare metal or if you are financially
unable to use the public cloud (at present GKE offers $400 CAD credit for a 1
year period which should be sufficient for a relatively short, resource non-intensive research project),
but it is very likely much more time consuming than it is worth to get Kubernetes up and running as
an individual researcher without extensive experience or connections to the Kubernetes community.

Ideally, Kubernetes will already be running and someone with expertise will be managing
the system so researchers can focus on developing and containerizing algorithms, and workflows--which
has its own learning curve.


