if [ $# -eq 0 ] ; then
  echo "Please specity the source"
  exit 1
fi
if [ ! -f $1 ] ; then
  echo "Source does not exist"
  exit 1
fi
make run SRC=$1 DEST=${2:-runbf}
exit $?
