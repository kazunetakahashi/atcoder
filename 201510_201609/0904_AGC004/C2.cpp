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
  for (auto i = 0; i < W; i++) {
    A[0][i] = '#';
  }
  for (auto i = 0; i < W; i++) {
    char c = '.';
    for (auto j = H-1; j >= 0; j--) {
      if (c == '.' && A[j][i] == '#') {
        c = '#';
      } else if (c == '#') {
        A[j][i] = c;
      }
    }
  }
  for (auto i = 0; i < H; i++) {
    for (auto j = 0; j < W; j++) {
      if (B[i][j] == '.' && A[i][j] == '.') {
        B[i][j] = '#';
      } else if (B[i][j] == '.' && A[i][j] == '#') {
        B[i][j] = '.';
      } else if (B[i][j] == '#' && A[i][j] == '.') {
        // assert(false);
      } else {
        B[i][j] = '#';
      }
    }
  }
  bool visited[2][510][510];
  fill(&visited[0][0][0], &visited[0][0][0]+2*510*510, false);
  for (auto l = 0; l < 2; l++) {
    stack<point> S;
    (l == 0 ? (S.push(make_pair(0, 0))) : (S.push(make_pair(H-1, 0))));
    while (!S.empty()) {
      int i = S.top().first;
      int j = S.top().second;
      S.pop();
      if (!visited[l][i][j]) {
        //cerr << "visiting : l = " << l
        //       << ", i = " << i << ", j = " << j << endl;
        visited[l][i][j] = true;
        for (auto k = 0; k < 4; k++) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          if (valid(ni, nj)
              && (l == 0 ? (A[ni][nj] == '#') : (B[ni][nj] == '#') )
              && !visited[l][ni][nj]) {
            S.push(make_pair(ni, nj));
          }
        }
      }
    }
    for (auto i = 0; i < H; i++) {
      for (auto j = 0; j < W; j++) {
        if((l == 0 ? (A[i][j] == '#') : (B[i][j] == '#') )
           && !visited[l][i][j]) {
          cerr << "error : l = " << l
               << ", i = " << i << ", j = " << j << endl;
          assert(false);
        }
      }
    }    
  }
  for (auto i = 0; i < H; i++) {
    cout << A[i] << endl;
  }
  for (auto i = 0; i < H; i++) {
    cout << B[i] << endl;
  }
}
