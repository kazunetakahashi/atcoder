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

int main () {
  int K;
  cin >> K;
  ll A[100010];
  for (auto i = 0; i < K; ++i) {
    cin >> A[i];
  }
  reverse(A, A+K);
  if (A[0] != 2) {
    cout << -1 << endl;
    return 0;
  }
  ll maxi = 3;
  ll mini = 2;
  for (auto i = 1; i < K; ++i) {
    ll tmini = (mini/A[i]) * A[i];
    if (mini > tmini) {
      tmini += A[i];
    }
    if (tmini > maxi) {
      cout << -1 << endl;
      return 0;      
    }
    ll tmaxi = (maxi/A[i]) * A[i] + A[i] - 1;
    maxi = tmaxi;
    mini = tmini;
  }
  cout << mini << " " << maxi << endl;
}
