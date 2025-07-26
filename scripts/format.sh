#!/usr/bin/env bash
set -e

if ! command -v clang-format >/dev/null 2>&1; then
  echo "clang-format not found"
  exit 1
fi

clang-format -i gpio.c gpio.h main.c tests/*.c tests/*.h
