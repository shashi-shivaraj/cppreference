CXX = g++

# Warnings frequently signal eventual errors:
CXXFLAGS=-g -std=c++14 -W -Wall -Weffc++ -Wextra -pedantic -O0

OBJS = ./src/main.o
OBJS += ./src/static.o
EXEC = run

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I ./inc

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

main.o: main.cpp
static.o: static.cpp

clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)
