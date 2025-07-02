COMPILER = clang
COMPILER_PLUS = clang++
# COMPILER = gcc-15
# COMPILER_PLUS = g++-15

# FLAGS =
FLAGS = -O3 -march=native

all: poc-c poc-cpp poc-cpp-2

poc-c: poc-c.c Makefile
	$(COMPILER) -o poc-c poc-c.c $(FLAGS)

poc-cpp: poc-cpp.cpp Makefile
	$(COMPILER_PLUS) -o poc-cpp poc-cpp.cpp $(FLAGS)

poc-cpp-2: poc-cpp-2.cpp Makefile
	$(COMPILER_PLUS) -o poc-cpp-2 poc-cpp-2.cpp $(FLAGS)
