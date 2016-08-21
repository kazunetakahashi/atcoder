#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <tuple>
#include <set>
#include <map>
#include <string>
#include <iomanip>
#include <cmath>
#include <cassert>
using namespace std;

typedef long long ll;

const int MAX_SIZE = 4000;
bool isprime[MAX_SIZE];
vector<ll> prime_num;
vector<ll> squered;
vector<ll> cubed;

const ll infty = 10000000010;

void init() {
  fill(isprime, isprime+MAX_SIZE, true);
  isprime[0] = isprime[1] = false;
  for (auto i=2; i<MAX_SIZE; i++) {
    if (isprime[i]) {
      ll x = i;
      prime_num.push_back(x);
      squered.push_back(x*x);
      cubed.push_back(x*x*x);
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

int N;
ll s[100010];
map<ll, int> M;

ll conj(ll k) {
  ll l = k;
  ll A = 1;
  ll B = 1;
  for (auto x : prime_num) {
    int t = 0;
    while (l % x == 0) {
      l /= x;
      t++;
    }
    if (t == 1) {
      A *= x;
    } else if (t == 2) {
      B *= x;
    }
  }
  ll red = k / (A * B * B);
  ll sq = floor(sqrt(red)+0.1);
  // cerr << "red = " << red << " , sq = " << sq << endl;
  if (red == sq * sq) {
    if (sq > 100010) return infty;
    B *= red;
  } else {
    if (red > 100010) return infty;
    A *= red;
  }
  return A * A * B;
}

int main() {
  init();
  cin >> N;
  int ans = 0;
  for (auto i = 0; i < N; i++) {
    cin >> s[i];
    for (auto x : cubed) {
      while (s[i]%x == 0) s[i] /= x;
    }
    if (M.find(s[i]) == M.end()) {
      M[s[i]] = 1;
    } else {
      M[s[i]]++;
    }
  }
  for (auto x : M) {
    ll k = x.first;
    int num = x.second;
    // cerr << k << " " << num << endl;
    if (k == 1 && num > 0) {
      ans += 1;
      continue;
    }
    ll c = conj(k);
    // cerr << "conj(" << k << ") = " << c << endl;
    if (M.find(c) == M.end()) {
      ans += num;
    } else {
      ans += max(num, M[c]);
      M[k] = 0;
      M[c] = 0;      
    }
  }
  cout << ans << endl;
}
