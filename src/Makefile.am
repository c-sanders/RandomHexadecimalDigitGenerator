# Automake provides some '-I' options automatically. The 3 -I options that Automake provides are ;
#
#   -I.
#   -I${srcdir}
#   -I which points to the directory holding 'config.h'
#
# The last '-I' will be provided if you have used AC_CONFIG_HEADERS or AM_CONFIG_HEADERS.
#
# You can disable the default '-I' options using the 'nostdinc' option. - Page 68 of Automake 
# version 1.10 manual.

# -lboost_chrono is needed for either or both of;
#
#   boost::this_thread::sleep_for
#   boost::chrono::seconds

bin_PROGRAMS  = main


main_SOURCES  = main.cpp \
                RandomHexadecimalDigitGenerator.cpp

main_INCLUDES = -I${top_srcdir}/include

main_LDFLAGS  =

main_LDADD    =


# C++ Preprocessor flags.
# -----------------------

main_CPPFLAGS = -std=c++11 \
                -DHAVE_CONFIG_H \
                ${main_INCLUDES}

# C++ Compilation flags.
# ----------------------

main_CXXFLAGS = 


.PHONY: displaySettings
displaySettings:

	@echo "srcdir               = ${srcdir}"
	@echo "abs_srcdir           = ${abs_srcdir}"
	@echo "top_srcdir           = ${top_srcdir}"
	@echo "builddir             = ${builddir}"
	@echo ""
	@echo "main_INCLUDES        = ${main_INCLUDES}"
	@echo "main_LDFLAGS         = ${main_LDFLAGS}"
	@echo "main_CPPFLAGS        = ${main_CPPFLAGS}"

