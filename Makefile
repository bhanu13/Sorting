EXENAME = sort
OBJS = main.o sort.o heap.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp sort.h
	$(CXX) $(CXXFLAGS) main.cpp

sort.o : sort.cpp sort.h heap.h
	$(CXX) $(CXXFLAGS) sort.cpp

heap.o : heap.cpp heap.h
	$(CXX) $(CXXFLAGS) heap.cpp

clean :
	-rm -f *.o $(EXENAME)