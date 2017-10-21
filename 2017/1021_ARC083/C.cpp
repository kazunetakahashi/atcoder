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
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  double nodo = 0;
  int sitsuryo = -1;
  int anssato = -1;
  for (auto i = 0; i <= 30; ++i) {
    for (auto j = 0; j <= 30; ++j) {
      int mizu = A * 100 * i + B * 100 * j;
      if (mizu > F) continue;
      int sato = F - mizu;
      sato = min(sato, mizu / 100 * E);
      for (auto k = 0; k * C > sato; ++k) {
        int nokori = sato - k * C;
        int realsato = k * C + (nokori/D) * D;
        double nownodo = ((double)realsato) / (realsato + mizu);
        cerr << "nownodo = " << nownodo << endl;
        if (nodo < nownodo) {
          nodo = nownodo;
          sitsuryo = realsato + mizu;
          anssato = realsato;
        }
      }
    }
  }
  cout << sitsuryo << " " << anssato << endl;
}
