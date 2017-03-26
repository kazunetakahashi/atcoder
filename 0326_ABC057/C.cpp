#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

const int MAX_SIZE = 100010; // 10000010でもよさそう？
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

int keta(ll A) {
  int ans = 1;
  while (A >= 10) {
    A /= 10;
    ++ans;
  }
  return ans;
}

int F(ll A, ll B) {
  return max(keta(A), keta(B));
}

int main() {
  init();
  ll N;
  cin >> N;
  int ans = keta(N);
  for (ll i = 1; i < 100010; ++i) {
    if (N % i == 0) {
      ans = min(ans, F(i, N/i));
    }
  }
  cout << ans << endl;
}
