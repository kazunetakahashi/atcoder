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

int t;
int D[1000];
int T[1000];
int C[1000][8];
int A[1000][8];
bool can[51];
bool can_ok = false;

int make_can() {
  fill(can, can+51, false);
  can[0] = true;
  for (auto i = 0; i < 8; ++i) {
    for (auto j = 50; j >= 0; --j) {
      if (can[j]) {
        int x = j + C[t][i];
        if (x <= 50) {
          can[x] = true;
        }
      }
    }
  }
  int ans = 0;
  for (auto i = 1; i <= 50; ++i) {
    if (can[i]) ++ans;
  }
  return ans;
}

void fill(int i) {
  cout << "fill " << i+1 << endl;
}

void move(int i, int j) {
  cout << "move " << i+1 << " " << j+1 << endl;
}

void change(int i) {
  cout << "change " << i+1 << endl;
}

void pass() {
  cout << "pass" << endl;
}

bool sell(vector<int> V) {
  int sum = 0;
  for (auto x : V) {
    sum += A[t][x];
  }
  if (D[t] == sum) {
    cout << "sell " << (int)V.size() << " ";
    for (auto i = 0; i < (int)V.size(); ++i) {
      cout << V[i]+1;
      if (i == (int)V.size()-1) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
    return true;
  } else {
    return false;
  }
}

bool filled(int i) {
  return (C[t][i] - A[t][i] == 0);
}

void output() {
  if (!can_ok) {
    if (make_can() >= 45) {
      can_ok = true;
    } else {
      vector<int> cnt[11];
      for (auto i = 0; i < 8; ++i) {
        cnt[C[t][i]].push_back(i);
      }
      for (auto i = 1; i <= 10; ++i) {
        if ((int)cnt[i].size() >= 2) {
          change(cnt[i][0]);
          goto EXIT;
        }
      }
    }
  }
  if (D[t] >= 10 && can[D[t]]) {
    for (auto i = 0; i < (1 << 8); ++i) {
      int am = 0;
      for (auto j = 0; j < 8; ++j) {
        if (((i >> j) & 1) == 1) {
          am += C[t][j];
        }
      }
      if (am == D[t]) {
        for (auto j = 0; j < 8; ++j) {
          if (((i >> j) & 1) == 1 && !filled(j)) {
            fill(j);
            goto EXIT;
          }
        }
        vector<int> V;
        for (auto j = 0; j < 8; ++j) {
          if (((i >> j) & 1) == 1) {
            V.push_back(j);
          }
        }
        sell(V);
        goto EXIT;
      }
    }
  } else {
    for (auto i = 0; i < 8; ++i) {
      if (!filled(i)) {
        fill(i);
        goto EXIT;
      }
    }
  }
  pass();
 EXIT:
  return;
}

int main () {
  for (t = 0; t < 1000; ++t) {
    cin >> D[t] >> T[t];
    for (auto i = 0; i < 8; ++i) {
      cin >> C[t][i];
    }
    for (auto i = 0; i < 8; ++i) {
      cin >> A[t][i];
    }
    output();
  }
}
