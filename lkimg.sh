#!/bin/bash
#cleanup
rm -rf lk.img build-msm8994/m/
sudo dd if=/dev/zero of=build-msm8994/lk.img bs=1 count=1M
sudo mkfs.vfat build-msm8994/lk.img
mkdir build-msm8994/m
sudo mount build-msm8994/lk.img build-msm8994/m
sudo cp build-msm8994/emmc_appsboot.mbn build-msm8994/m/
sudo umount build-msm8994/m