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
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

typedef long long ll;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const int M = 1000000007;

const int MAX_SIZE = 1000010; // 10000010でもよさそう？
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

long long gcm(long long a, long long b) {
  if (a < b) {
    return gcm(b, a);
  }
  if (b == 0) return a;
  return gcm(b, a%b);
}

int N;
ll K;
ll A[200010];
map<ll, ll> M;
map<ll, ll> X;
vector<int> primes;

int sum(ll s) {
  ll ans = 0;
  for (auto x : M) {
    ll youso = x.first;
    ll kazu = x.second;
    if (youso % s == 0) {
      ans += kazu;
    }
  }
  return ans;
}

int main () {
  init();
  cin >> N >> K;
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (auto i = 0; i < N; i++) {
    A[i] = gcm(A[i], K);
    if (M.find(A[i]) == M.end()) {
      M[A[i]] = 1;
    } else {
      M[A[i]]++;
    }
  }
  for (auto x : prime_num) {
    if (K%x == 0) {
      primes.push_back(x);
    }
  }
  ll ans = 0;
  for (auto x : M) {
    ll youso = x.first;
    ll kazu = x.second;
    //cerr << "youso = " << youso << ", kazu = " << kazu << endl;
    //cerr << "sum(" << K/youso << ") = " << sum(K/youso) << endl;
    ans += sum(K/youso) * kazu;
  }
  for (auto i = 0; i < N; i++) {
    if ((A[i] * A[i]) % K == 0) {
      ans--;
    }
  }
  cout << ans/2 << endl;
}
