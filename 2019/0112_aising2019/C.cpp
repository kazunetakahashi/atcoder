/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 1/12/2019, 9:05:30 PM
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
#include <functional>
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(19920725));
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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

typedef tuple<int, int> P;

// const int C = 1e6+10;
// const ll M = 1000000007;

int H, W;
string S[410];
bool visited[410][410];

int main()
{
  cin >> H >> W;
  for (auto i = 0; i < H; i++)
  {
    cin >> S[i];
  }
  fill(&visited[0][0], &visited[0][0] + 410 * 410, false);
  ll ans = 0;
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      if (!visited[i][j])
      {
        stack<P> St;
        St.push(P(i, j));
        ll cnt[2] = {0, 0};
        while (!St.empty())
        {
          int x = get<0>(St.top());
          int y = get<1>(St.top());
          St.pop();
          if (!visited[x][y])
          {
            visited[x][y] = true;
            cnt[S[x][y] == '#']++;
            for (auto k = 0; k < 4; k++)
            {
              int nx = x + dx[k];
              int ny = x + dy[k];
              if (0 <= nx && nx < H && 0 <= ny && ny < W && S[x][y] != S[nx][ny])
              {
                St.push(P(nx, ny));
              }
            }
          }
        }
        ans += cnt[0] * cnt[1];
      }
    }
  }
  cout << ans << endl;
}