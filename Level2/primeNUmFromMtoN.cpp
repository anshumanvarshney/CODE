/*
generate all prime number from m to n
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iterator>

bool is_prime (const int& n, std::vector<int>& v);

int main() {
  int t;
  std::cin >> t;
  std::vector<int> prime_array;

  // build the sieve
  for (int i=2; i<=100000; i++)
    if ( is_prime( i, prime_array ) ) 
        prime_array.push_back( i );

  while (t--) {
    long long m;
    long long n;

    std::cin >> m;
    std::cin >> n;

    if (m<2) m = 2;

    //check for the prime numbers in the range.
    for (int i=m; i<=n; i++)
      if ( is_prime( i, prime_array ) ) 
        std::cout << i << std::endl;
    std::cout << std::endl;

  }
  return 0;
}
