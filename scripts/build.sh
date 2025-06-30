#!/usr/bin/env bash
set -e

if [ "$1" = "clean" ]; then
  make clean
  exit 0
fi

make
