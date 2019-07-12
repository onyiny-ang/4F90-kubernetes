# Deploy Argo Workflows :octopus:

Once Kubernetes is up and running and you have your algorithm containerized, 
you can create yaml files to define workflows to deploy on your Kubernetes cluster.
One workflow manager is Argo.
There are several research appropriate argo workflows defined in [the argo directory of this repo](../argo).

To deploy Argo on your [Kubernetes cluster](kubernetes.md), follow the steps outlined in the [demo](https://github.com/argoproj/argo/blob/master/demo.md)
