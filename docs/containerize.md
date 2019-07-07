# Containerizing your algorithm with Docker

Containers are lightweight blah blah blah

Let's take a look at the container for the salmon algorithm:

```
FROM ubuntu:latest

RUN apt-get -y update && apt-get install -y

FROM gcc:4.9

COPY SalmonTSP/temp /SalmonTSP

WORKDIR /SalmonTSP/

RUN g++ -o Salmon *.cpp *.h

WORKDIR /

```

That's it! That's the container that runs the salmon algorithm. So let's take a
closer look at all of the steps involved.

1. Provide the base image for the container.

  A container requires an image, just like a regular computer (if you've ever
  installed linux, think about your container as your computer pre-install).

  ```
  # Get the base Ubuntu image from Docker Hub
  FROM ubuntu:latest
  ```

  This gets the latest ubuntu container image from the Docker Hub and pulls it
  into the container.

2. Run and install updates

  This step will be familiar for anyone that has run Ubuntu before, it is
  simply the command to run and install the updates to the latest ubuntu image.

  ```
  # Update apps on the base image
  RUN apt-get -y update && apt-get install -y
  ```

The next steps will vary depending on your specific algorithm/use cases so I
will keep the concepts more general.

3. Get libraries specific to your algorithm

  In this case, the container will be running the
  [Salmon](https://github.com/onyiny-ang/salmon) algorithm which is written in
  c++ and requires the gcc compiler to build. One major benefit of containers
  is that we are able to build our own containers with the libraries we need and
  only the libraries we need--making them more lightweight and remove the
  burden on system administrators to manage these libraries at the system
  level. Running docker does require root access to your system, so you may
  have to build your containers on a machine that you can install docker onto,
  but this _should_ be a relatively trivial and non-resource intensive task.

  ```
  # Get the GCC preinstalled image from Docker Hub
  FROM gcc:4.9
  ```

4. Move your algorithm into the container

  In this case, I am copying a folder container all of the source files for the
  Salmon algorithm from my local system (or git repo) into the container.

  ```
  # Copy the current folder which contains C++ source code to the Docker image under /usr/src
  COPY SalmonTSP/temp /SalmonTSP
  ```

5. Specify the working directory for executable commands

  If you want to execute or run anything inside of the container, the working
  directory must be specified. In this case, we will be compiling the Salmon
  algorithm and so the working directory must be set to where the source files
  are located.

  ```
  # Specify the working directory
  WORKDIR /SalmonTSP/
  ```

6. Run your executable

  In this case, we are compiling the Salmon algorithm into an executable with
  the help of the gcc library that was installed earlier. This simply compiles
  the algorithm just like a typical c++ program would be compiled.

  ```
  # Use Clang to compile the Test.cpp source file
  RUN g++ -o Salmon *.cpp *.h
  ```

7. Optionally reset the working directory to a predicatable place

  Set the working directory back to root, which would be expected by anyone
  using the container.

  ```
  WORKDIR /
  ```

That's it!


I found [this](https://amytabb.com/ts/2018_07_28/#hello-world-with-arguments) article by Amy Tabb to be helpful in configuring the Dockerfile.

## Extending your containerization

Containerization is beneficial for the reasons that were mentioned at the top
of the page, but it also allows for further automation since the same type of
container would work for any configuration of the salmon algorithm. Designing
the workflow in this way makes it very simple to extend the algorithm for
similar uses. For example, in the case of the salmon algorithm, it is used for
both TSP as well as DNA Fragment Assembly problems and I use the same
Dockerfile to build all of my salmon containers (and eventually created an automated CI/CD workflow to build and run them all automatically! That work can be found in my [salmon repo](https://github.com/onyiny-ang/salmon)) and only have to alter the files that are moved into the `/SalmonTSP/temp` folder prior to being copied to the container (see step 4). This makes organizing research much cleaner, while providing other benefits like reproducability (literally anyone else could build or use the same container to test and verify your results and extend your research).

The next step is creating [argo workflows](argo.md).
