# Requesting Resources from Compute Canada

## NOTE: It is not advisable for researchers to request resources in order to build their own kubernetes cluster through compute Canada. 
In some cases it may make sense, but a significant amount of your time will likely be spent just getting the cluster up and running. Consider other options (ie. see if Compute Canada has an existing cluster that researchers can use or try a Kubernetes cluster managed by a public cloud provider: [GKE](gcloud.md), [AWS](https://aws.amazon.com/kubernetes/), [Azure](https://azure.microsoft.com/en-ca/services/kubernetes-service/), etc) first.   

If you decide to proceed with building your own cluster:

The PI for your project will need to request resources on your behalf. This can
be done by:

## Research using a Compute Canada RAS

The RAS was provided through WestGrid's [Arbutus cloud](https://www.westgrid.ca/support/systems/arbutus) which operates out of the
University of Victoria. Through the [VISPA](https://www.uvic.ca/science/physics/vispa/) research center and ATLAS group at the University of Victoria, there is some research into the utility of Kubernetes, particularly as it pertains to processing filtered data from the Large Hadron Collider at CERN. This research is particular to the ATLAS specific use case and it is unclear at what level Compute Canada will be adopting Kubernetes going forward.
At present, researchers interested in Kubernetes and provided a [RAS](https://www.computecanada.ca/research-portal/accessing-resources/rapid-access-service/) to experiment on
Arbutus, will be given access to the Arbutus cloud login (credentials will be the
same as the login on other Compute Canada systems). There are instructions for
Compute Canada's cloud resources [here](https://docs.computecanada.ca/wiki/Cloud). This will provide an
openstack interface and access to the RAS allocated resources on openstack.

When requesting RAS resources, the following information must be provided. At
present, it is advisable to request the maximum resources when deploying a
Kubernetes project from scratch:
```
> CCUserName: <username>
> PI: Yes
> Request: New project + RAS request
> ProjectType: Compute
> VCPUs: MAX
> Instances: MAX
> Volumes: MAX
> Snapshots: MAX
> RAM: MAX
> FloatingIPs: 5
> Storage: MAX
> ExplainNeed: Research project involving distributing AI workloads with Kubernetes
> ExplainWhyCloud: We need to install Kubernetes ourselves
> ExplainEfficiency: We are exploring the use of Kubernetes for research purposes,
> combinatorial optimization, i.e. the main purpose is to find the most efficient
> way to use the resources.
> ExplainSecurity: OS will be kept up to date on VM. No outside access by others -
> for use by researchers ,applicant and student only, for research runs.
```

Once the RAS is created, users will be able to create virtual machines with root privileges and use this to launch a Kubernetes deployment with tools like
[kubespray](https://github.com/kubernetes-sigs/kubespray), [terraform](https://github.com/hashicorp/terraform) and [ansible](https://www.ansible.com/) (See [examples](openstack.md)).

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


