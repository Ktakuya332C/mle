CXX = g++
CXXFLAGS = -Wall -std=c++11

eum_test: eum_test.o eum.o
	$(CXX) $(CXXFLAGS) $^ -o $@

eum_test.o: eum_test.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

eum.o: eum.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.PHONY: clean
clean:
	rm *.o eum_test
