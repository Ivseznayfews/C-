#!/bin/bash
cd "$(dirname "$0")"

find . -name "Makefile" -type f | while read makefile; do
    dir=$(dirname "$makefile")
    echo "=== 编译 $dir ==="
    (cd "$dir" && make)
done
