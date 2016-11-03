#!/bin/sh
# Run this to generate all the initial makefiles, etc.
# NOTE:
#   We automatically clone the gvc submodule, and this is included within
#   the "make dist" tarball- you need this to package Budgie!
#   See issue: 303
#
srcdir=`dirname $0`
test -n "$srcdir" || srcdir=`dirname "$0"`
test -n "$srcdir" || srcdir=.

PKG_NAME="budgie-global-menubar-applet"
prevdir="$PWD"
cd "$srcdir"

AUTORECONF=`which autoreconf`
if test -z $AUTORECONF;
then
  echo "*** No autoreconf found, please install it ***"
  exit 1
else
  libtoolize -i || exit $?
  autoreconf --force --install || exit $?
fi

DEF_OPTS="--prefix=/usr --sysconfdir=/etc"

cd "$prevdir"
test -n "$NOCONFIGURE" || "$srcdir/configure" ${DEF_OPTS} "$@"
