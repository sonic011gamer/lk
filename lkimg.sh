#!/bin/bash
#cleanup
rm -rf lk.img build-msm8994/m/
sudo dd if=/dev/zero of=build-msm8994/lk.img bs=1 count=1M
sudo mkfs.vfat build-msm8994/lk.img
mkdir build-msm8994/m
sudo mount build-msm8994/lk.img build-msm8994/m
sudo cp build-msm8994/emmc_appsboot.mbn build-msm8994/m/
sudo umount build-msm8994/m

rm -rf lk.img build-msm8974/m/
sudo dd if=/dev/zero of=build-msm8974/lk.img bs=1 count=1M
sudo mkfs.vfat build-msm8974/lk.img
mkdir build-msm8974/m
sudo mount build-msm8974/lk.img build-msm8974/m
sudo cp build-msm8974/emmc_appsboot.mbn build-msm8974/m/
sudo umount build-msm8974/m