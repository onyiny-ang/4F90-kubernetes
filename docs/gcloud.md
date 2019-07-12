# Now for something completely different

To deploy Kubernetes on Google cloud, ignore all of the resource requesting and kubespray/terraform/ansible instructions. Public cloud providers make spinning up Kubernetes clusters comparatively simple.
You can sign up for free and get $300USD free credit to play with.
[Download the gcloud CLI](https://cloud.google.com/sdk/). You can do this on Linux/Mac
with:

```
curl https://sdk.cloud.google.com | bash
```

Once installed, log in and update it:

```
gcloud auth login
gcloud components update
```

Then deploy a kubernetes cluster with the following
command:
```
gcloud container clusters create gke-us-east1 \
  --zone=us-east1-b --scopes "cloud-platform"
```
Double check that the cluster is actually there:

```
gcloud container clusters list
```

Check that your kubernetes cluster appears in your kubeconfig:

```
kubectl config get-clusters
```
You should see it listed in the output from that command.

Just like that, you now have a kubernetes cluster. It almost seems like cheating. Now you can just [deploy away](containerize.md).






