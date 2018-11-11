CXX = g++
CXXFLAGS = -Wall -std=c++11

mle_test: mle_test.o mle.o
	$(CXX) $(CXXFLAGS) $^ -o $@

mle_test.o: mle_test.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

mle.o: mle.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm *.o mle_test

