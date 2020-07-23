CXX = g++

# Warnings frequently signal eventual errors:
CXXFLAGS=-g -std=c++14 -W -Wall -Weffc++ -Wextra -pedantic -O0

all : clean exe val

OBJS = \
	./src/main.o
EXEC = run

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

exe : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS) $(LDFLAGS)

main.o: main.cpp

val:
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./run

clean:
	rm -rf $(OBJS)
	rm -rf $(EXEC)
