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
typedef pair<int, int> point;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const int M = 1000000007;

int H, W;
string a[510];
string A[510];
string B[510];

bool valid(int i, int j) {
  return (0 <= i && i < H && 0 <= j && j < W);
}

int main () {
  cin >> H >> W;
  for (auto i = 0; i < H; i++) {
    cin >> a[i];
    A[i] = a[i];
    B[i] = a[i];
  }
  for (auto i = 0; i < H; i++) {    
    for (auto j = 1; j < W-1; j++) {
      if (i%2 == 0) {
        A[i][j] = '#';
      } else {
        B[i][j] = '#';
      }
    }
  }
  for (auto i = 0; i < H; i++) {
    A[i][0] = '#';
    B[i][W-1] = '#';
  }
  for (auto i = 0; i < H; i++) {
    cout << A[i] << endl;
  }
  for (auto i = 0; i < H; i++) {
    cout << B[i] << endl;
  }
}
