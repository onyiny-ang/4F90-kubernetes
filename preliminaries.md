## Singularity vs Kubernetes

[Source](https://kubernetes.io/blog/2017/08/kubernetes-meets-high-performance/)


Anyone who has worked with Docker can appreciate the enormous gains in efficiency achievable with containers. While Kubernetes excels at orchestrating containers, high-performance computing (HPC) applications can be tricky to deploy on Kubernetes
Kubernetes base unit of scheduling is a pod which is one or more Docker containers scheduled to a cluster host-- Kubernetes has the notion of cron jobs/Jobs but is typically used for long-running services (web servers, load balancers, data stores)

While the notion of __packaging a workload into a Docker container, publishing it to a registry, and submitting a YAML description of the workload__ is second nature to users of Kubernetes, this is foreign to most HPC users. An analyst running models in R, MATLAB or Stata simply wants to submit their simulation quickly, monitor their execution, and get a result as quickly as possible.

### Bottom Line

We might need to compromise on an approach.

#### Existing Approaches

- separate infrastructures
- run containerized workloads under existing HPC workload manager (not ideal for our purposes, but might be a place to start)

  The idea is to use HPC workloads to instantiate Docker containers on target hosts ([Singularity](http://singularity.lbl.gov/) is one such example).
- __use native job scheduling features__ (likely the ideal approach for our purposes)

  may be impractical for many HPC users. HPC applications are often either optimized towards massive throughput or large scale parallelism. In both cases startup and teardown latencies have a discriminating impact. Latencies that appear to be acceptable for containerized microservices today would render such applications unable to scale to the required levels.

#### Mixed Workloads on Kube


### Non-expert Opinion:

There may be some options but they will each require a fair amount of work:
- Try some franken-architecture that will not be optimal but will hopefully run
  Kubernetes (ie. Use Singularity to deploy Kubernetes on SLURM. . .)

- Use the public cloud (GCE, AWS, Azure)
- Compare each of these approaches?
- Abandon this idea or refocus the efforts
- Kubernetes can run SLURM--could also make infrastructure more versatile but
  is it worth it to try to prove this?
- Just because it's theorhetically possible to do these things, it doesn't mean
  that it's well tested or understood so I could get stuck down a dark well
  just trying to get the darn thing to work if we go for a frankenarchitecture.
