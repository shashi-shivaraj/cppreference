CXX = g++

ARCHIVER = ar
OPT = rcs

# Warnings frequently signal eventual errors:
CXXFLAGS=-g -std=c++14 -W -Wall -Weffc++ -Wextra -pedantic -O0


LIB_OBJS = ./src/lib.o

OBJS = \
	./src/main.o

LIB = libsample.a
EXEC = run

all: lib exe

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I ./inc/

lib: $(LIB_OBJS)
	$(ARCHIVER) $(OPT) $(LIB) $(LIB_OBJS)

lib.o: lib.cpp

exe: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS) $(LDFLAGS) -L. -lsample

#-L : current directory
#-l : link library

main.o: main.cpp

clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)
	rm -rf $(LIB_OBJS)
	rm -rf $(LIB)