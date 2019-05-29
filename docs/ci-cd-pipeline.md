# CI/CD Integration with Kubernetes

Many Kubernetes native applications provide varying degrees of continuous
integration and continuous deployment that can be configured to abstract away
many steps of the development process. This provides the user with nearly
immediate feedback for any changes they make which makes for a more seamless
development process. For researchers, implementing a CI/CD pipeline for
containerized workflows can enable researchers to focus on what's important
rather than having to manually recompile, run a slew of bash or python scripts to abstract data and resubmit to the scheduler. By configuring an event triggered CI/CD pipeline and utilizing free services like github, a researcher can, for example, alter 3 parameters of an algorithm they are testing, push the changes to github, and have the pipeline build the updated [containers](containerize.md), push them to the container registry and trigger the kubernetes job to rerun the workflow, printing the results, all with a single `git push`.


It is necessary to familiarize oneself with git, as well as a one of several
different tools. In fact, the most difficult part of this step is to determine
which tool to use for CI/CD with a Kubernetes workflow.

## Kuberentes native CI/CD tools:

1. Prow

2. Tekton

3. Kubeflow

4. Argo Events


## Other notable solutions:

1. Travis:

  Travis is notable because it is, at the time of writing, still widely used to
  build, test and run commands on github repos. Some projects use travis to
  run all existing tests for each pending pull request and each merge to the master
  branch. It can also be used to build containers and push containers to a
  container registry like [Quay](quay.io) or [docker hub](dockerhub.com).
  Travis has also been used to integrate prow and other CI/CD commands but it
  is not in and of itself able to manage the entire CI/CD pipeline.
