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

string rep(string c, int n) {
  string ans = "";
  for (auto i = 0; i < n; ++i) {
    ans += c;
  }
  return ans;
}

string repa(int n) {
  return rep("A", n);
}

string repb(int n) {
  return rep("B", n);
}

ll calc_K(ll A, ll B) {
  ll ub = 500000010;
  ll lb = 0;
  while (ub - lb > 1) {
    ll t = (ub+lb)/2;
    if (A <= (B+1) * t && B <= (A+1) * t) {
      ub = t;
    } else {
      lb = t;
    }
  }
  return ub;
}

string f(int A, int B, int C, int D) {
  ll K = calc_K(A, B);
  ll ub = A+B;
  ll lb = -1;
  while (ub - lb > 1) {
    ll t = (ub+lb)/2;
    ll b = t/(K+1);
    ll a = t - b;
    ll rema = A - a;
    ll remb = B - b;
    if (remb <= (rema+1) * K) {
      ub = t;
    } else {
      lb = t;
    }
  }
  ll L = ub;
  if (D <= L) {
    int back = (C/(K+1)) * (K+1);
    C -= back;
    D -= back;
    string X = rep(repa(K) + "B", 100);
    return X.substr(C-1, D-C+1);
  } else if (C > L) {
    C = A+B+1-C;
    D = A+B+1-D;
    int back = (C/(K+1)) * (K+1);
    C -= back;
    D -= back;    
    string X = rep(repb(K) + "A", 100);
    string Y = X.substr(D-1, D-C+1);
    reverse(Y.begin(), Y.end());
    return Y;
  } else {
    int rema = L%(K+1);
    int remb = (A+B-L)%(K+1);
    string X = repa(rema) + repb(remb);
    X = rep(repa(K) + "B", 100) + X + rep("A" + repb(K), 100);
    int back = L - (100 * (K+1) + rema);
    C -= back;
    D -= back;
    return X.substr(C-1, D-C+1);    
  }
}

int main () {
  int Q;
  cin >> Q;
  int A[1010], B[1010], C[1010], D[1010];
  for (auto i = 0; i < Q; ++i) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }
  for (auto i = 0; i < Q; ++i) {
    string X = f(A[i], B[i], C[i], D[i]);
    cout << X << endl;
  }
}
