CXX = g++

LIB_OPT = -shared
COMPILE_OPT = -fpic

# Warnings frequently signal eventual errors:
CXXFLAGS=-g -std=c++14 -W -Wall -Weffc++ -Wextra -pedantic -O0


LIB_OBJS = ./src/lib.o

OBJS = \
	./src/main.o

LIB = libsample.so
EXEC = run

all: lib exe

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(COMPILE_OPT) -c $< -o $@ -I ./inc/

lib: $(LIB_OBJS)
	$(CXX) $(LIB_OPT) -o $(LIB) $(LIB_OBJS)

lib.o: lib.cpp

exe: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS) $(LDFLAGS)

#-L : current directory
#-l : link library

main.o: main.cpp

clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)
	rm -rf $(LIB_OBJS)
	rm -rf $(LIB)