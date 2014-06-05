#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include "utils.h"
using namespace std;

unordered_map<int, string> phone;

string construct_candidates(vector<char> a, int k, vector<int> input) {
  return phone[input[k]];
}

bool is_solution(vector<char> a, int k, vector<int> input) {
  return (k == input.size() - 1);
}

void process_solution(vector<char> a, int k, vector<int> input) {
  for (auto it = a.begin(); it != a.end(); it++)
    cout << *it;
  cout << endl;
}

void backtrack(vector<char> a, int k, vector<int> input) {

  if (is_solution(a, k,input))
    process_solution(a, k, input);
  else {
    k = k + 1;
    string candidates = construct_candidates(a, k, input);
    for (size_t i = 0; i < candidates.length(); i++) {
      a.push_back(candidates[i]);
      backtrack(a, k, input);
      a.pop_back();
    }
  }
}


int main() {
  vector <char> s;
  phone[2] = "ABC";
  phone[3] = "DEF";
  phone[4] = "GHI";
  phone[5] = "JKL";
  phone[6] = "MNO";
  phone[7] = "PQRS";
  phone[8] = "TUV";
  phone[9] = "WXYZ";

  backtrack(s, -1, {7,2,2,5,2,4,7,3,8,6});
}
