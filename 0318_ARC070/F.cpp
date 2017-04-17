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

int A, B, N;
int kind[4010]; // 0: undecided, 1: honest, 2: lier

bool que(int a, int b) {
  cout << "? " << a << " " << b << endl;
  string ans;
  cin >> ans;
  return (ans == "Y");
}

void solve() {
  vector<int> V;
  int P = 0, Q = 0;
  for (auto i = 0; i < N; ++i) {
    if (kind[i] == 0) {
      V.push_back(i);
    } else if (kind[i] == 1) {
      ++P;
    } else {
      ++Q;
    }
  }
  P = A - P;
  Q = B - Q;
  if (P == 0) {
    for (auto i = 0; i < N; ++i) {
      if (kind[i] == 0) {
        kind[i] = 2;
      }
    }
    return;
  } else if (Q == 0) {
    for (auto i = 0; i < N; ++i) {
      if (kind[i] == 0) {
        kind[i] = 1;
      }
    }
    return;
  }
  for (auto ind = 0; ind < (int)V.size(); ++ind) {
    if (que(V[ind], V[ind+1])) continue;
    vector<int> hon;
    vector<int> lie;
    for (auto j = 1; j < (int)V.size(); ++j) {
      int ask = (ind + j)%((int)V.size());
      if (que(V[ask], V[ind])) {
        hon.push_back(ask);
      } else {
        lie.push_back(ask);
      }
      if ((int)hon.size() >= P-1) {
        kind[V[ind]] = 1;
        for (auto x : lie) {
          kind[V[x]] = 2;
        }
        if (ind != 0) {
          int h = ((que(V[ind], V[0])) ? 1 : 2);
          for (auto i = 0; i < ind-1; ++i) {
            kind[V[i]] = h;
          }
        }
        for (auto i = 0; i < N; ++i) {
          if (kind[i] == 0) {
            kind[i] = ((que(V[ind], i)) ? 1 : 2);
          }
        }
        return;
      } else if ((int)lie.size() >= P-1) {
        kind[V[ind]] = 2;
        for (auto x : hon) {
          kind[V[x]] = 2;
        }
        solve();
      }
    }
  }
}

int main () {
  cin >> A >> B;
  N = A + B;
  if (A <= B) {
    cout << "Impossible" << endl;
    return 0;
  }
  fill(kind, kind+4010, 0);
  solve();
  for (auto i = 0; i < N; ++i) {
    cout << ((kind[i] == 1) ? 1 : 0);
  }
  cout << endl;
}
