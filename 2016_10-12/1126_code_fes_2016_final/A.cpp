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

int main () {
  int H, W;
  cin >> H >> W;
  string S[100][100];
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      cin >> S[i][j];
    }
  }
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      if (S[i][j] == "snuke") {
        cout << (char)('A'+j);
        cout << i+1;
        cout << endl;
        return 0;
      }
    }
  }
}
