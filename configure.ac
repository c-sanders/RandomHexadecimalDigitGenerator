# ------------------------------------------------------------------------------
# Filename : configure.ac
# =======================
#
# Process this file with autoconf to produce a configure script.
# ------------------------------------------------------------------------------


AC_INIT(
        [random_hexadecimal_digit_generator],
        [0.0.1],
        [craig@gravitas-toolworks.com],
        [random_hexadecimal_digit_generator])

# Specify the location into which the auxiliary build tools
# should be placed, that is;
#
#   - compile
#   - config.guess
#   - config.sub
#   - depcomp
#   - install-sh
#   - missing

AC_CONFIG_AUX_DIR([config])

AM_INIT_AUTOMAKE([
	1.15
	foreign
	-Wall])

AC_CONFIG_SRCDIR([src/main.cpp])

# Tell Autoconf where certain macros should be loaded from.
# ---------------------------------------------------------
#
# In particular, this file (configure.ac) makes use of the
# following third party Autoconf macros;
#
#   - ax_boost_base.m4
#   - ax_boost_thread.m4

AC_CONFIG_MACRO_DIRS([m4])

# AC_LANG_SOURCE

AC_PROG_CXX

AM_PROG_AR

AC_PROG_LIBTOOL

# AC_PROG_CXX(
#             [${CXX}])

# AC_PROG_CXX()

# AX_BOOST_BASE([1.74.0])

# AX_BOOST_THREAD()

# Required if targets which depend on C source code files posess per-target flags.

# AC_PROG_CC_C_O
# AM_PROG_CC_C_O

AC_PROG_LIBTOOL

AC_OUTPUT([
           Makefile
           src/Makefile
])
