TARGETS := fib array_sum qsort iterative

all: clean $(TARGETS) clean-obj

%: %.cpp
	$(CXX) -O3 -std=c++11 -o $@ $^ -lm

clean-obj:
	rm -rf *.o

clean:
	rm -rf *.o $(TARGETS)
