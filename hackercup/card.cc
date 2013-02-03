#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;
std::vector<long> maxv;

using namespace std;
long pow(long a, long x, long p) {
  long res = 1;
  while(x > 0) {
    if( x % 2 != 0) {
      res = (res * a) % p;
      x--;
    }
    a = (a * a) % p;
    x /= 2;
  }
  return res;
}

long inverse(long a, long p) {
  return pow(a, p-2, p);
}
long binomial(long n, long k, long p) {

  long numerator = 1; // n * (n-1) * ... * (n-k+1)
  for (int i=0; i<k; i++) {
    numerator = (numerator * (n-i) ) % p;
  }
  long denominator = 1; // k!
  for (int i=1; i<=k; i++) {
    denominator = (denominator * i) % p;
  }

  return ( numerator* inverse(denominator,p) ) % p;
}



int compare( const void * a, const void * b ) {
  return ( *(int*)b - *(int*)a );
}


int main()
{
  int test_num;
  cin >> test_num;
  int j = 0;
  int n, k;
  long p = 1000000007;
  while (j < test_num) {
    cin >> n;
    cin >> k;
    long a[n];
    long t[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    qsort (a, n, sizeof(long), compare);

    long sum = 0;
    long f = 0;
    while ( (n -f - 1) >= (k - 1)) {
      long num = a[f];
      long comb = binomial(n - f - 1 , k - 1, p);
      sum = (sum + (num % p ) * (comb % p)) % p;
      f++;
    }

    for(std::vector<long>::iterator it = maxv.begin(); it != maxv.end(); ++it) {
      sum = (sum + *it) % p;
    }

    j++;
    cout << "Case #" << j << ": " << sum << endl;
    maxv.erase(maxv.begin(), maxv.end());
  }
  return 0;
}
