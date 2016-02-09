CXXFLAGS +=  -std=c++11 -Wall -g 
LIBS = -lpthread
GTEST_DIR = gtest/googletest


all: leetcode_test

clean:
	rm *.o leetcode_test

run: leetcode_test
	./leetcode_test

leetcode_test: test.cpp googletest.o
	${CXX} ${CXXFLAGS} ${LIBS} -isystem ${GTEST_DIR}/include  test.cpp googletest.o -o leetcode_test 

googletest.o: gtest/googletest/src/gtest-all.cc
	${CXX} ${CXXFLAGS} -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -c $< -o $@

.PHONY: all clean run