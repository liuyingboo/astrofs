#!/bin/bash

FULLPATH=$(cd "$(dirname "$0")";pwd)
echo "============================================"
echo "Full Path to Current Executable Script : ${FULLPATH}"
echo "============================================"
BASEDIR=`dirname $FULLPATH`

echo "============================================"
echo "Jump to Parent Folder: $BASEDIR"
echo "============================================"
cd $BASEDIR
ls -lsh

echo "============================================"
echo "!!!Current Working Directory: ${BASEPATH}"
echo "============================================"

libtoolize --copy --force # copy micro to m4 folder
aclocal
autoheader
autoconf -v

if [ "$BASEDIR" == "$FULLPATH" ];then
    echo "Wrong Working Direcory!"
	exit
fi

if [ ! -f "AUTHORS" ]; then
    echo "AUTHORS"
    touch AUTHORS
fi

if [ ! -f "NEWS" ]; then
    echo "NEWS"
    touch NEWS
fi

if [ ! -f "README" ]; then
	echo "README"
    touch README
fi

if [ ! -f "ChangeLog" ]; then
    echo "ChangeLog"
    touch ChangeLog
fi


automake --add-missing --copy --gnu

./configure CFLAGS="-gdwarf-2 -g3 -O0" 

echo "============================================"
echo "./configure has done. Run [make & make install] "
echo "============================================"


