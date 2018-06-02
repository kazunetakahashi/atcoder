/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-6-2 22:17:13
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
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

ll H, W;
ll N, M;
string A[1010];
bool S[1010][1010];
bool F[1010][1010];

int main()
{
  cin >> H >> W;
  cin >> N >> M;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < M; j++)
    {
      S[i][j] = (A[i][j] == '#');
    }
  }
  fill(&F[0][0], &F[0][0] + 1010 * 1010, false);
  for (auto s = 0; s <= H - N; s++)
  {
    for (auto t = 0; t <= W - M; t++)
    {
      for (auto i = 0; i < N; i++)
      {
        for (auto j = 0; j < M; j++)
        {
          F[i][j] = (F[i][j] && S[s + i][t + j]);
        }
      }
    }
  }
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      cout << (F[i][j] ? '#' : '.');
    }
    cerr << endl;
  }
}