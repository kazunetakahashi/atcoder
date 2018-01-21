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

int N, K;
int cnt[2000][2000][2];
int sum[2000][2000][2];

int main () {
  fill(&cnt[0][0][0], &cnt[0][0][0]+2000*2000*2, 0);
  cin >> N >> K;
  int white = 0;
  for (auto i = 0; i < N; ++i) {
    int x, y;
    char c;
    cin >> x >> y >> c;
    bool color = (c == 'W');
    int area = ((x/K) + (y/K))%2;
    x %= K;
    y %= K;
    if (color) {
      white++;
      cnt[x + K * area][y][0]++;
      cnt[x + K * area][y + K][0]++;
    } else {
      cnt[x + K * area][y][1]++;      
      cnt[x + K * area][y + K][1]++;      
    }
  }
  for (auto k = 0; k < 2; ++k) {
    cerr << "k = " << k << endl;
    for (auto i = 0; i < 2 * K; ++i) {
      for (auto j = 0; j < 2 * K; ++j) {
        cerr << cnt[i][j][k] << " ";
      }
      cerr << endl;
    }    
  }
  for (auto k = 0; k < 2; ++k) {
    for (auto i = 0; i < 2 * K; ++i) {
      for (auto j = 0; j < 2 * K; ++j) {
        sum[i][j][k] = cnt[i][j][k];
      }
    }
    for (auto i = 0; i < 2 * K; ++i) {
      for (auto j = 0; j < 2 * K-1; ++j) {
        sum[i][j+1][k] += sum[i][j][k];
      }
    }
    for (auto j = 0; j < 2 * K; ++j) {
      for (auto i = 0; i < 2 * K-1; ++i) {
        sum[i+1][j][k] += sum[i][j][k];
      }
    }
  }
  for (auto k = 0; k < 2; ++k) {
    cerr << "k = " << k << endl;
    for (auto i = 0; i < 2 * K; ++i) {
      for (auto j = 0; j < 2 * K; ++j) {
        cerr << sum[i][j][k] << " ";
      }
      cerr << endl;
    }    
  }
  int ans = 0;
  for (auto i = 0; i < K; ++i) {
    for (auto j = 0; j < K; ++j) {
      int x = i + K;
      int y = j + K;
      int w = sum[x][y][0] - sum[i][y][0] - sum[x][j][0] + sum[i][j][0];
      int b = sum[x][y][1] - sum[i][y][1] - sum[x][j][1] + sum[i][j][1];
      cerr << "(" << x << ", " << y << ") = ("
           << w << ", " << b << ")" << endl;
      int c = white - w + b;
      ans = max(ans, c);
    }
  }
  cout << ans << endl;
}
