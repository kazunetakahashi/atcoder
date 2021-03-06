#define DEBUG 1

/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-26 21:05:46
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

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int N, M;
int k[100];
int s[100][100];
int p[100];

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    cin >> k[i];
    for (auto j = 0; j < k[i]; j++)
    {
      cin >> s[i][j];
      s[i][j]--;
    }
  }
  for (auto i = 0; i < M; i++)
  {
    cin >> p[i];
  }
  int ans = 0;
  for (auto i = 0; i < (1 << N); i++)
  {
    bool ok = true;
    for (auto j = 0; j < M; j++)
    {
      int cnt = 0;
      for (auto l = 0; l < k[j]; l++)
      {
        if ((i >> s[j][l]) & 1)
        {
          cnt++;
        }
      }
      if (cnt % 2 != p[j])
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      ans++;
    }
  }
  cout << ans << endl;
}