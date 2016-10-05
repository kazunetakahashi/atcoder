#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <tuple>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;

int table[360][360];

int imossum[360][360];
ll imoscnt[10][360][360];

int calc_sum(int a, int b, int c, int d) {
  return imossum[c][d]
    - ((a>0) ? imossum[a-1][d] : 0)
    - ((b>0) ? imossum[c][b-1] : 0)
    + (((a>0)&&(b>0)) ? imossum[a-1][b-1] : 0);
}

ll calc_cnt(int ind, int a, int b, int c, int d) {
  return imoscnt[ind][c][d]
    - ((a>0) ? imoscnt[ind][a-1][d] : 0)
    - ((b>0) ? imoscnt[ind][c][b-1] : 0)
    + (((a>0)&&(b>0)) ? imoscnt[ind][a-1][b-1] : 0);
}

int main() {
  int R, C, K;
  cin >> R >> C >> K;
  for (auto i = 0; i < R; i++) {
    string S;
    cin >> S;
    for (auto j = 0; j < C; j++) {
      table[i][j] = (S[j] - '0');
    }
  }
  fill(&imossum[0][0], &imossum[0][0]+360*360, 0);
  fill(&imoscnt[0][0][0], &imoscnt[0][0][0]+360*360, 0);
  for (auto i = 0; i < R; i++) {
    for (auto j = 0; j < C; j++) {
      imossum[i][j] = table[i][j];
    }
  }
  for (auto i = 0; i < R-1; i++) {
    for (auto j = 0; j < C; j++) {
      imossum[i+1][j] += imossum[i][j];
    }
  }
  for (auto i = 0; i < R; i++) {
    for (auto j = 0; j < C-1; j++) {
      imossum[i][j+1] += imossum[i][j];
    }
  }
  for (auto i = 0; i < 10; i++) {
    for (auto j = 0; j < R; j++) {
      for (auto k = 0; k < C; k++) {
        imoscnt[i][j][k] = ((table[j][k] == i) ? 1 : 0);
      }
    }
    for (auto j = 0; j < R-1; j++) {
      for (auto k = 0; k < C; k++) {
        imoscnt[i][j+1][k] += imoscnt[i][j][k];
      }
    }
    for (auto j = 0; j < R; j++) {
      for (auto k = 0; k < C-1; k++) {
        imoscnt[i][j][k+1] += imoscnt[i][j][k];
      }
    }
  }
}
