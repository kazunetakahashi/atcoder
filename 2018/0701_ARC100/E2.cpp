/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-7-1 22:00:11
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

const int M = (1 << 18);

typedef tuple<int, int> D;

int N;
int A[M];

set<D> DP[20][M];

int main()
{
  cin >> N;
  for (auto i = 0; i < (1 << N); i++)
  {
    cin >> A[i];
  }
  for (auto i = 0; i < (1 << N); i++)
  {
    DP[0][i].insert(D(-A[i], i));
  }
  for (auto i = 1; i <= N; i++)
  {
    for (auto j = 0; j < (1 << N); j++)
    {
      auto it = DP[i - 1][j].begin();
      DP[i][j].insert(*it);
      it++;
      if (it != DP[i - 1][j].end())
      {
        DP[i][j].insert(*it);
      }
      if ((j >> i) & 1)
      {
        it = DP[i][j - (1 << i)].begin();
        DP[i][j].insert(*it);
        it++;
        if (it != DP[i][j - (1 << i)].end())
        {
          DP[i][j].insert(*it);
        }
      }
      cerr << "DP[" << i << "][" << j << "] = ";
      for (auto e : DP[i][j])
      {
        cerr << "(" << -get<0>(e) << ", " << get<1>(e) << ") ";
      }
      cerr << endl;
    }
  }
  int ans = 0;
  for (auto i = 1; i < (1 << N); i++)
  {
    int tmp = 0;
    auto it = DP[N][i].begin();
    tmp += -get<0>(*it);
    it++;
    tmp += -get<0>(*it);
    ans = max(ans, tmp);
    cout << ans << endl;
  }
}