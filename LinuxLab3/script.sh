#!/bin/bash

SCRIPT_DIR=$(dirname "$(realpath "$0")")

find "$SCRIPT_DIR" -mindepth 1 -maxdepth 1 -type d \
    -exec du -s {} \; | sort -n | tail -3