#!/bin/bash

set -o nounset
set -o errexit
set -o pipefail

sudo apt-get update
sudo apt-get install -y build-essential bison flex unzip libpopt-dev libpopt0 \
	libnetpbm10 libnetpbm10-dev

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

tar zxf ../vice-2.3.tar.gz
pushd vice-2.3/
mkdir hack
cat << EOF > hack/config.h
#define PREFIX "/usr/local"
#define SIZEOF_UNSIGNED_SHORT 2
#define SIZEOF_UNSIGNED_INT 4
#define HAVE_MKSTEMP
#define HAVE_DIRENT_H
#define HAVE_ERRNO_H
#define HAVE_LIMITS_H
#define HAVE_FCNTL_H
#define HAVE_UNISTD_H
#define HAVE_STRINGS_H
EOF
sh src/gentranslate_h.sh < src/translate.txt > hack/translate.h
gcc -Ihack -Isrc -Isrc/arch/unix src/petcat.c src/arch/unix/archdep.c \
	src/lib.c src/log.c src/util.c src/findpath.c \
	src/ioutil.c src/resources.c -o src/petcat
sudo mv src/petcat /usr/local/bin/petcat
popd
