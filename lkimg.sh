#!/bin/bash
#cleanup
make ARCH=arm TOOLCHAIN_PREFIX=~/arm-eabi/bin/arm-eabi- msm8909
rm -rf lk.img build-msm8909/m/
sudo dd if=/dev/zero of=build-msm8909/lk.img bs=1 count=1M
sudo mkfs.vfat build-msm8909/lk.img
mkdir build-msm8909/m
sudo mount build-msm8909/lk.img build-msm8909/m
sudo cp build-msm8909/emmc_appsboot.mbn build-msm8909/m/
sudo umount build-msm8909/m
