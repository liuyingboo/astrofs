#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.63])
AC_INIT([AstroFS], [0.1], [])
#AC_CONFIG_SRCDIR([src/consist/main.c])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE

# Things required by automake
AC_ARG_PROGRAM

# Checks for programs.
AC_PROG_CC
AC_PROG_AWK
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_RANLIB
AC_PROG_LIBTOOL


# Checks for libraries.
have_pthreads=no
AC_SEARCH_LIBS([pthread_create],[pthread],[have_pthreads=yes])
if test "x${have_pthreads}" = xyes; then
                AC_CHECK_HEADERS([pthread.h],[],[have_pthreads=no])
fi

if test "x${have_pthreads}" = xno; then
                AC_MSG_WARN([
                -------------------------------------------------------------
                Unable to find on this system.
                Building a single-threaded version
                -------------------------------------------------------------])
fi
AC_CHECK_LIB([gdsl],[gdsl_list_alloc],[],[
			AC_MSG_ERROR([You need to have GDSL installed!])
			])

# Checks for header files.
AC_CHECK_HEADERS([sys/time.h stdlib.h stdio.h unistd.h])

AC_CHECK_HEADERS([gdsl.h],[],[
                AC_MSG_WARN([
                -------------------------------------------------------------
                Unable to find The Generic Data Structures Library on this system.
				Please refer to http://home.gna.org/gdsl/
				Note: version > 1.7
                -------------------------------------------------------------])
			])



# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# 定义PTHREAD的LDFLAG，以在Makefile.am中加入到链接器参数中去。
PTHREAD_LIBS=-lpthread
AC_SUBST(PTHREAD_LIBS)

GDSL_LIBS=`gdsl-config --libs`
AC_SUBST(GDSL_LIBS)

GDSL_CFLAGS=`gdsl-config --cflags`
AC_SUBST(GDSL_CFLAGS)

AC_CONFIG_FILES([Makefile
		 doc/Makefile
		 src/Makefile
		 src/client/Makefile
		 src/manserver/Makefile
		 src/common/Makefile
         src/metaserver/Makefile
		 src/test/Makefile
		 src/utils/Makefile
         src/dataserver/Makefile])

AC_OUTPUT
