#include "hclib.hpp"
#include<iostream>

#define SIZE (104857600)
#define THRESHOLD (8192)
int array[SIZE];

int sum(int low, int high) {
  if((high-low) > THRESHOLD) {
    int x, y;
    int mid = (low+high)/2;
    hclib::finish([&]() {
      hclib::async([&]() {
        x = sum(low, mid);
      });
      y = sum(mid, high);
    });
    return x+y;
  } else {
    int x=0;
    for(int i=low; i<high; i++) x+= array[i];
    return x;
  }
}

int main (int argc, char ** argv) {
    hclib::init(argc, argv);
    std::fill(array, array+SIZE, 1);
    int result = 0;
    hclib::kernel([&]() {
      result = sum(0, SIZE);
    });
    if(result == SIZE) std::cout<<"Test passed\n";
    else std::cout<<"Test failed\n";
    hclib::finalize();
  return 0;
}

