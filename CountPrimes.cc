
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <numeric>

using namespace std;

int countPrimes(int n) {
  if (n <= 2)
    return 0;
  int *primes = (int *)malloc(n * sizeof(int));
  for (int i = 2; i < n; i++)
    primes[i] = 1;
  for (int i = 2; i <= sqrt(n - 1); i++) {
    if (primes[i]) {
      for (int j = i + i; j < n; j += i)
        primes[j] = 0;
    }
  }
  int count = 0;
  for (int i = 2; i < n; i++)
    if (primes[i])
      count++;
  free(primes);
  return count;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}