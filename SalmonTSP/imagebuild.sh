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

#!/bin/bash

set -o errexit
set -o nounset
set -o pipefail

root_dir="$(cd "$(dirname "$0")/.." ; pwd)"
base_dir="${root_dir}"
dockerfile_dir="${base_dir}/images/Salmon-TSP/Dockerfile"
cd "$base_dir" || {
  echo "Cannot cd to '$base_dir'. Aborting." >&2
  exit 1

}
cd ${base_dir}

export REGISTRY=quay.io/
temp_dir="build/temp"
mkdir -p ${temp_dir}

echo "Copy salmon files"

#cp ${base_dir}/SalmonTSP/berlin52.txt ${temp_dir}/berlin52.txt
#cp ${base_dir}/SalmonTSP/*cpp ${temp_dir}/
#cp ${base_dir}/SalmonTSP/*h ${temp_dir}/
#cp ${base_dir}/SalmonTSP/randomseed.txt ${temp_dir}/randomseed.txt

echo "Building Salmon docker image"

#For testing purposes

echo "Pushing images with default tags (git sha and 'canary')."
docker build -f ${dockerfile_dir} -t ${REGISTRY}onyiny_ang/salmon-tsp:berlin-canary .
  docker push ${REGISTRY}onyiny_ang/salmon-tsp:berlin-canary
