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

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int N, M;
string A[60];
string B[60];

bool match(int x, int y) {
  for (auto i = 0; i < M; ++i) {
    for (auto j = 0; j < M; ++j) {
      if (A[i+x][j+y] != B[i][j]) return false;
    }
  }
  return true;
}

int main () {
  cin >> N >> M;
  for (auto i = 0; i < N; ++i) {
    cin >> A[i];
  }
  for (auto i = 0; i < M; ++i) {
    cin >> B[i];
  }
  for (auto i = 0; i <= N-M; ++i) {
    for (auto j = 0; j <= N-M; ++j) {
      if (match(i, j)) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
