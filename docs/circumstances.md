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
over recent years to address the change in demands ([Charlie Cloud](), [Singularity](https://journals.plos.org/plosone/article?id=10.1371/journal.pone.0177459))[1][2],
each with their own strengths and pitfalls.

Kubernetes, is an opensource container orchestration tool that has gained wide
spread popularity in the industry. Based on Google's internal tool [Borg](https://kubernetes.io/blog/2015/04/borg-predecessor-to-kubernetes/)[3], it was released as an
opensource tool in 2011 and has become the industry standard for container orchestration.
Because of it's wide appeal and cloud agnosticism, investigating the usefulness of
Kubernetes for research purposes has merit. It has been shown to have success in the
machine learning and AI space and is paramount to filtering and processing data generated
from the Large Hadron Collider through CERN. It seems that Kubernetes could help academic
research computing effectively manage and provide solutions for the changing needs of
researchers, but at what cost? This paper will investigate Kubernetes repurposed as a
research tool, test it's effectiveness for running Bioinformatics algorithms and give a
broad synopsis of it's utility for research computing. It will also outline painpoints
that are known and that were encountered throughout the investigation.
```

## Research under a Canadian Principal Investigator

As quoted in the Compute Canada Research Portal [access policy](https://www.computecanada.ca/research-portal/accessing-resources/access-policy/):

```
Compute Canada’s national platform of systems and services is accessible to all Canadian
researchers. Compute Canada facilities are designated for Canadian researchers, or those
collaborating on Canadian research projects, with significant advanced research computing
(ARC) requirements.

```

Academic Principal Investigators are able to sponser students to request
Resource Allocation through competitions [RAC](https://www.computecanada.ca/research-portal/accessing-resources/resource-allocation-competitions/) and Rapid Access Service [RAS](https://www.computecanada.ca/research-portal/accessing-resources/rapid-access-service/) for a modest amount of storage and cloud resources. This project required a [RAS request](resources.md) with the maximum RAS allocation (maximum RAS amount for cores, instances and RAM, 5 networks, 5 routers, 5 IPS). [Dr. Sheridan Houghten](https://www.cosc.brocku.ca/~houghten/) is a faculty
member of Brock University and acted as the Academic Principal Investigator for this
project. This provided access, free of charge, to compute and storage resources and services, including access to advanced computing experts made available by Compute
Canada.

For more information on using a Compute Canada RAS, see the
[Resources](resources.md) documentation.

There are situations where launching a Kubernetes deployment on bare metal or on private cloud insstances with Openstack may make sense, (for example: in order to keep sensitive data on premise, investigating/exploring Kubernetes or creating a proof of concept that specifically involves running Kubernetes on bare metal/openstack or if you are financially
unable to use the public cloud (at present GKE offers $400 CAD credit for a 1
year period which should be sufficient for a relatively short, resource non-intensive research project),
but it is very likely much more time consuming than it is worth to get Kubernetes up and running as
an individual researcher without extensive experience or connections to the Kubernetes community.

Ideally, Kubernetes will already be running and someone with expertise will be managing
the system so researchers can focus on developing and containerizing algorithms, and workflows--which
has its own learning curve, but is much more beneficial to invest time in learning.

