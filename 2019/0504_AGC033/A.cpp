#define DEBUG 1

/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 5/4/2019, 9:01:22 PM
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
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(10101010));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int H, W;
string A[1010];
int visited[1010][1010];
typedef tuple<int, int, int> P;
queue<P> Q;

int main()
{
  cin >> H >> W;
  for (auto i = 0; i < H; i++)
  {
    cin >> A[i];
  }
  fill(&visited[0][0], &visited[0][0] + 1010 * 1010, -1);
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      if (A[i][j] == '#')
      {
        Q.push(P(i, j, 0));
      }
    }
  }
  int ans = 0;
  while (Q.empty())
  {
    int x = get<0>(Q.front());
    int y = get<1>(Q.front());
    int c = get<2>(Q.front());
    Q.pop();
    if (visited[x][y] == -1)
    {
      visited[x][y] = c;
      ans = max(ans, c);
      for (auto k = 0; k < 4; k++)
      {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < H && 0 <= ny && ny < W && visited[nx][ny] == -1)
        {
          Q.push(P(nx, ny, c + 1));
        }
      }
    }
  }
  cout << ans << endl;
}
