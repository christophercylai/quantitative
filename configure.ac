# Autoconf Init
AC_PREREQ([2.71])
AC_INIT([quant], [1.01], [christophercylai@outlook.com], [quant], [https://github.com/christophercylai/quantitative])
AC_CONFIG_SRCDIR([src/quant.cpp])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL

AC_CONFIG_AUX_DIR([auxiliary])
AC_CHECK_HEADER_STDBOOL

AM_PROG_AR
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_FILES([Makefile src/Makefile])

LT_INIT

AC_OUTPUT
