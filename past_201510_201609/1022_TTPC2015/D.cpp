#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

const int MAX_SIZE = 100010;
bool isprime[MAX_SIZE];
vector<int> prime_num;

void init() {
  fill(isprime, isprime+MAX_SIZE, true);
  isprime[0] = isprime[1] = false;
  for (auto i=2; i<MAX_SIZE; i++) {
    if (isprime[i]) {
      prime_num.push_back(i);
      for (auto j=2; i*j<MAX_SIZE; j++) {
        isprime[i*j] = false;
      }
    }
  }
}

bool prime(long long x) { // 2 \leq x \leq MAX_SIZE^2
  if (x < MAX_SIZE) {
    return isprime[x];
  }
  for (auto e : prime_num) {
    if (x%e == 0) return false;
  }
  return true;
}

int main() {
  init();
  string S;
  cin >> S;
  map<char, int> M;
  for (auto x : S) {
    if (M.find(x) == M.end()) {
      int m = M.size();
      M[x] = m;
    }
  }
  if (M.size() >= 6) {
    cout << "-1" << endl;
    return 0;
  }
  vector<int> V;
  for (auto x : S) {
    V.push_back(M[x]);
  }
  char A[5] = { '1', '3', '5', '7', '9' };
  do {
    string T = "";
    for (auto x : V) {
      // cerr << "A[" << x << "] = " << A[x] << endl;
      T += A[x];
      // cerr << T << endl;
    }
    if (prime(stoll(T))) {
      cout << T << endl;
      return 0;
    }
  } while (next_permutation(A, A+5));
  cout << -1 << endl;
}
