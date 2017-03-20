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

int D[1000];
int T[1000];
int C[1000][8];
int A[1000][8];

void fill(int i) {
  cout << "fill " << i << endl;
}

void move(int i, int j) {
  cout << "move " << i << " " << j << endl;
}

void change(int i) {
  cout << "change " << i << endl;
}

void pass() {
  cout << "pass" << endl;
}

void sell(vector<int> V) {
  cout << "sell " << (int)V.size() << " ";
  for (auto i = 0; i < (int)V.size(); ++i) {
    cout << V[i];
    if (i == (int)V.size()-1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}

void output(int t) {
  pass();
}

int main () {
  for (auto t = 0; t < 1000; ++t) {
    cin >> D[t] >> T[t];
    for (auto i = 0; i < 8; ++i) {
      cin >> C[t][i];
    }
    for (auto i = 0; i < 8; ++i) {
      cin >> A[t][i];
    }
    output(t);
  }
}
