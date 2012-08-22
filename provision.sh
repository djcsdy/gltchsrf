#!/bin/bash

set -o nounset
set -o errexit
set -o pipefail

sudo apt-get install -y build-essential bison flex unzip libpopt-dev libpopt0 \
	libnetpbm10 libnetpbm10-dev vice

cd /vagrant/tools/
rm -rf build
mkdir -p build
cd build

tar zxf ../k2asm-1.0bRC3.tar.gz
pushd k2asm-1.0bRC3/
CPPFLAGS='-fpermissive -include stdlib.h' ./configure
make
sudo make install
popd

unzip ../k2xkernel-0.9.zip
pushd k2xkernel-0.9/
make
popd

unzip ../k2codingtools-1.0.zip
pushd k2codingtools-1.0/
make
sudo make install
popd

unzip ../k2disktools-0.9.zip
pushd k2disktools-0.9/
make
sudo make install
popd

unzip ../k2graphictools-0.2.zip
pushd k2graphictools-0.2/
make
sudo make install
popd

unzip ../k2profiler-1.0.zip
pushd k2profiler-1.0/
make
sudo make install
popd
