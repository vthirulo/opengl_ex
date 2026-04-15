#!/usr/bin/bash

if [[ $1 == "--clean" ]]; then
  rm -rf bin build .cache
  rm compile_commands.json
  cmake --preset base-linux
fi

cmake --build --preset Linux-Build -j $(nproc)
