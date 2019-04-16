# Copyright 2018 The Kubernetes Authors.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.


# Get the base Ubuntu image from Docker Hub
FROM ubuntu:latest

#Create argument for container
#ENV NAME VAR
# Update apps on the base image
RUN apt-get -y update && apt-get install -y

# Get the GCC preinstalled image from Docker Hub
FROM gcc:4.9

# Copy the current folder which contains C++ source code to the Docker image under /usr/src
COPY SalmonTSP/temp /SalmonTSP

# Specify the working directory
WORKDIR /SalmonTSP/

# Use Clang to compile the Test.cpp source file
RUN g++ -o Salmon *.cpp *.h


WORKDIR /

# Run the output program from the previous step
#CMD ["/bin/sh", "/SalmonTSP/Salmon"]
