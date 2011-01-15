#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.64])
AC_INIT(bathmoi, 1.0, forfolias@linuxteam.cs.teilar.gr)
AM_INIT_AUTOMAKE(bathmoi, 1.0)
AC_CONFIG_SRCDIR([bathmoi.c])
AM_PROG_CC_STDC
AC_DEFUN([AM_PATH_GTK], true)


AM_PATH_GTK_2_0(2.18.0, CFLAGS="$CFLAGS $GTK_CFLAGS" LIBS="$LIBS $GTK_LIBS", AC_MSG_ERROR(Cannot find GTK: Is gtk-config in path?))

AC_OUTPUT(Makefile)
