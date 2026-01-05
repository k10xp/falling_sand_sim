#!/bin/bash
mkdir -p build
cd external/raylib/src
make PLATFORM=PLATFORM_DESKTOP -B
