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

string S, T;



int main () {
  cin >> S >> T;
  int N = S.size();
  int M = T.size();
  vector<string> V;
  for (auto i = 0; i < N - M; ++i) {
    string X = S;
    for (auto j = 0; j < M; ++j) {
      X[i + j] = T[j];
    }
    for (auto i = 0; i < N; ++i) {
      if (X[i] == '?') X[i] = 'a';
    }
    cerr << X << endl;
    V.push_back(X);
  }
  sort(V.begin(), V.end());
  for (auto X : V) {
    bool ok = true;
    for (auto i = 0; i < N; ++i) {
      if (S[i] != '?' && S[i] != X[i]) ok = false;
    }
    if (ok) {
      cout << X << endl;
      return 0;
    }
  }
  cout << "UNRESTORABLE" << endl;
}
