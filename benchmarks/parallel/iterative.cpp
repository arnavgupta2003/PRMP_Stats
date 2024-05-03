#include "hclib.hpp"
/*
 * Ported from HJlib
 *
 * Author: Vivek Kumar
 *
 */

//48 * 256 * 2048
#define SIZE 10485760
#define ITERATIONS 64
#define THRESHOLD 1024

double* myNew, *myVal;
int n;

int ceilDiv(int d) {
  int m = SIZE / d;
  if (m * d == SIZE) {
    return m;
  } else {
    return (m + 1);
  }
}

void recurse(uint64_t low, uint64_t high) {
  if((high - low) > THRESHOLD) {
    uint64_t mid = (high+low)/2;
    hclib::finish([=]() {
      hclib::async([=]() {
        recurse(low, mid);  
      });
      recurse(mid, high);
    });
  } else {
    for(uint64_t j=low; j<high; j++) {
      myNew[j] = (myVal[j - 1] + myVal[j + 1]) / 2.0;
    }
  }
}

void runParallel() {
  for(int i=0; i<ITERATIONS; i++) {
    recurse(1, SIZE+1);
    double* temp = myNew;
    myNew = myVal;
    myVal = temp;
  }
}

int main(int argc, char** argv) {
  hclib::init(argc, argv);
  myNew = new double[(SIZE + 2)];
  myVal = new double[(SIZE + 2)];
  memset(myNew, 0, sizeof(double) * (SIZE + 2));
  memset(myVal, 0, sizeof(double) * (SIZE + 2));
  myVal[SIZE + 1] = 1.0;
  hclib::kernel([=]() {
    runParallel();
  });
  delete(myNew);
  delete(myVal);  
  hclib::finalize();
}

