#!/usr/bin/env bash
set -e

make -C tests clean all
fail=0
for t in tests/test_*; do
  if [ -x "$t" ]; then
    if ! "$t"; then
      fail=1
    fi
  fi
done
if [ "$fail" -ne 0 ]; then
  echo "Tests failed"
  exit 1
fi
echo "All tests passed"
