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

const int MAX_SIZE = 1000010;
const long long MOD = 1000000007;

long long inv[MAX_SIZE];
long long fact[MAX_SIZE];
long long factinv[MAX_SIZE];

void init() {
  inv[1] = 1;
  for (int i=2; i<MAX_SIZE; i++) {
    inv[i] = ((MOD - inv[MOD%i]) * (MOD/i))%MOD;
  }
  fact[0] = factinv[0] = 1;
  for (int i=1; i<MAX_SIZE; i++) {
    fact[i] = (i * fact[i-1])%MOD;
    factinv[i] = (inv[i] * factinv[i-1])%MOD;
  }
}

long long C(int n, int k) {
  if (n >=0 && k >= 0 && n-k >= 0) {
    return ((fact[n] * factinv[k])%MOD * factinv[n-k])%MOD;
  }
  return 0;
}

long long power(long long x, long long n) {
  if (n == 0) {
    return 1;
  } else if (n%2 == 1) {
    return (x * power(x, n-1)) % MOD;
  } else {
    long long half = power(x, n/2);
    return (half * half) % MOD;
  }
}

long long gcm(long long a, long long b) {
  if (a < b) {
    return gcm(b, a);
  }
  if (b == 0) return a;
  return gcm(b, a%b);
}

int main () {
  init();
  int N;
  cin >> N;
  int A[100010];
  for (auto i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A+N);
  bool isodd = (N%2 == 1);
  for (auto i = 0; i < N; i++) {
    if (isodd ^ (A[i]%2 == 1)) {
      
    } else {
      cout << 0 << endl;
      return 0;
    }
  }
  if (isodd) {
    for (auto i = 0; i < N; i++) {
      if (i%2 == 0) {
        if (A[i] != i) {
          cout << 0 << endl;
          return 0;
        }
      } else {
        if (A[i] != i+1) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
    cout << power(2, (N-1)/2) << endl;
    return 0;
  } else {
    for (auto i = 0; i < N; i++) {
      if (i%2 == 0) {
        if (A[i] != i+1) {
          cout << 0 << endl;
          return 0;
        }
      } else {
        if (A[i] != i) {
          cout << 0 << endl;
          return 0;
        }
      }
    }
    cout << power(2, N/2) << endl;
    return 0;
  }
}
