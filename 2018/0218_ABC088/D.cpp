/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-18 21:11:18
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>   // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set>
#include <random> // random_device rd; mt19937 mt(rd());
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

typedef tuple<int, int, int> state;

// const int C = 1e6+10;
// const ll M = 1000000007;

int H, W;
string S[100];

bool valid(int x, int y) {
  return (0 <= x && x < H && 0 <= y && y < W && S[x][y] == '.');
}

int main()
{
  cin >> H >> W;
  for (auto i = 0; i < H; i++)
  {
    cin >> S[i];
  }
  int cnt = 0;
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      if (S[i][j] == '#')
        cnt++;
    }
  }
  queue<state> Q;
  Q.push(make_tuple(0, 0, 0));
  while (!Q.empty()) {
    int c = get<0>(Q.front());
    int x = get<1>(Q.front());
    int y = get<2>(Q.front());
    Q.pop();
    if (x == H - 1 && y == W - 1)
    {
      cout << H * W - cnt - (c + 1) << endl;
      return 0;
    } else if (!(S[x][y] == '.')) {
      S[x][y] = '#';
      for (auto k = 0; k < 4; k++)
      {
        int nc = c + 1;
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (valid(nx, ny)) {
          Q.push(make_tuple(nc, nx, ny));
        }
      }
    }
  }
  cout << "-1" << endl;
}