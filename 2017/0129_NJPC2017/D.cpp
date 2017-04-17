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
#include <deque>
using namespace std;

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C ;
// const ll M = 1000000007;

int N, M, K;
int ans[110][110];

int main () {
  cin >> N >> M >> K;
  bool irekae = false;
  if (N > M) {
    swap(N, M);
    irekae = true;
  }
  fill(&ans[0][0], &ans[0][0]+110*110, -1);
  bool reverse = (N * M * (M-1)/2 <= K);
  if (reverse) {
    K = N * M * (M-1)/2 + M * N * (N-1)/2 - K; 
  }
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < M; j++) {
      ans[i][j] = 1 + i * M + j;
    }
  }
  int row = 0;
  int now = 0;
  while (K > 0) {
    assert(row < N);
    if (now < M-1 && ans[row][now] < ans[row][now+1]) {
      swap(ans[row][now], ans[row][now+1]);
      K--;
      now++;
    } else if (now == 0) {
      row++;
    } else {
      now = 0;
    }
  }
  if (irekae) {
    for (auto i = 0; i < 110; i++) {
      for (auto j = i+1; j < 110; j++) {
        swap(ans[i][j], ans[j][i]);
      }
    }
    swap(N, M);
  }  
  if (reverse) {
    for (auto i = 0; i < N; i++) {
      for (auto j = 0; j < M; j++) {
        cout <<  N * M + 1 - ans[i][j];
        if (j < M-1) {
          cout << " ";
        } else {
          cout << endl;
        }
      }
    }
  } else {
    for (auto i = 0; i < N; i++) {
      for (auto j = 0; j < M; j++) {
        cout <<  ans[i][j];
        if (j < M-1) {
          cout << " ";
        } else {
          cout << endl;
        }
      }
    }
  }
}
