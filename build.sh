#!/bin/bash

TOOLCHAIN_PATH="../gcc-arm-none-eabi-9-2019-q4-major/bin"
TOOLCHAIN_PREFIX="arm-none-eabi-"
TARGET="msm8610"

export PATH=${TOOLCHAIN_PATH}:${PATH}

make "TOOLCHAIN_PREFIX=${TOOLCHAIN_PREFIX}" "${TARGET}"
