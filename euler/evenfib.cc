#include <iostream>

using namespace std;



int main() {

  long MAX = 4000000;
  long j = 1, k = 2;
  long current = k;
  long sum = 2;
  while (current < MAX) {
    current = j + k;
    cout << current << endl;
    if (current % 2 == 0)
      sum += current;
    j = k;
    k = current;

  }
  cout << sum << endl;

}
