CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

OBJS = llrec-test.o llrec.o

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o llrec-test llrec-test.o llrec.o

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 