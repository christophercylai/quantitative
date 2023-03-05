termdir = $(abs_top_srcdir)
term_DATA = term.cpp

utildir = $(abs_top_srcdir)
util_DATA = util.cpp
util_CPPFLAGS = $(PY_FLAGS)

functiondir = $(abs_top_srcdir)
function_DATA = function.cpp
function_CPPFLAGS = $(PY_FLAGS)

quantdir = $(abs_top_srcdir)
quant_LTLIBRARIES = libquant.la
libquant_la_SOURCES = quant.cpp function.o util.o term.o
libquant_la_CPPFLAGS = $(PY_FLAGS)
