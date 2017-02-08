make
if [ $# -eq 0 ] ; then
  echo "Please specity the source"
  exit 1
fi
if [ ! -f $1 ] ; then
  echo "Source does not exist"
  exit 1
fi
./toc $1
if [ -f "brainfuck.c" ] ; then
  gcc -w -o ${2:-runbf} "brainfuck.c"
  rm "brainfuck.c"
  exit 0
fi
echo "Compilation failed."
exit 1
