VERSION="1.0"

CCOMPILER=gcc
CXXCOMPILER=g++
CC  = $(CCOMPILER)
CXX = $(CXXCOMPILER)


CODE_COVERAGE= -fprofile-arcs -ftest-coverage

WARNINGS=-fpermissive -Wno-missing-declarations -Wall -Wextra \
-Wpedantic -pedantic-errors -Wno-unused-parameter


COMPFLAGS = $(WARNINGS) $(CODE_COVERAGE) -g  -std=c++17 -fPIC

#-fsanitize=address -fsanitize-memory-track-origins -fno-omit-frame-pointer  #
#-DDENSE #-DPROJECT_DEBUG
 #-DPRINT_GRADT#-DPRINT_TAYLOR -DPRINT_LINEARIZING
 #-DHAVE_TBB -DPRINT_TAYLOR_NODES\



#use original fadbad with power corrected

INCLUDES += -I../src/ #-ICatch2/include

LDFLAGS += -L/usr/lib/gcc/x86_64-linux-gnu/7/

LDLIBS  += -lstdc++ -lgcov -llapack -lblas -lgfortran -lquadmath -ladolc -lm -lklu -lbtf -lspqr -lsuitesparseconfig -lcholmod -lamd -lcolamd -lyaml-cpp


CXXFLAGS += $(COMPFLAGS)  $(INCLUDES)
CFLAGS   += $(COMPFLAGS)  $(INCLUDES)

all: tc

tc: tc.o

clean: 
	rm tc.o tc