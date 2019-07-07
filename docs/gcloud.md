# Now for something completely different

Just ignore all of the set up details and just deploy on Google cloud.
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

Wasn't that ridiculously easy?

Just double check the cluster is actually there, because I'm skeptical after
all of that terraform finagling:

```
gcloud container clusters list
```
Who knew it could be this easy? Google does. So does Amazon by the way, and
Microsoft is certainly working on it, so what's  _your_ plan?

Anyway, now you have a kubernetes cluster. It almost seems like cheating. Now you can just deploy away.




