#!/bin/bash
src=`readlink -e $1`
dest=`readlink -e $2`
cd "$(dirname "$0")"
if [ $# -eq 0 ] ; then
  echo "Please specity the source"
  exit 1
fi
if [ ! -f $src ] ; then
  echo "Source does not exist"
  exit 1
fi
make run SRC=$src DEST=${dest:-runbf} >/dev/null
exit $?
