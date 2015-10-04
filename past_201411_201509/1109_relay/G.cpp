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
#include <set> // if (S.find(key) != S.end()) { }
// for (auto i=S.begin(); i != S.end(); i++) { }
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
using namespace std;

//const int dx[4] = {1, 0, -1, 0};
//const int dy[4] = {0, 1, 0, -1};

const int C = 100000;
bool DP[55][C]; // DP[i][j]; i番目までの目覚ましの和で音量jを実現可能か？

int main() {
  int n, m;
  cin >> n >> m;
  int a[55];
  for (auto i=0; i<n; i++) {
    cin >> a[i];
    // cerr << a[i] << endl;
  }
  fill(&DP[0][0], &DP[0][0]+55*C, false);
  DP[0][0] = true;
  for (auto i=0; i<n; i++) {
    for (auto j=0; j<C; j++) {
      if (DP[i][j]) {
	DP[i+1][j] = true;
	// cerr << i+1 << " " << j << endl;
	if (j+a[i] < C) {
	  DP[i+1][j+a[i]] = true;
	  // cerr << i+1 << " " << j+a[j] << endl;
	}
      }
    }
  }
  for (auto i=m; i<C; i++) {
    if (DP[n][i]) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
