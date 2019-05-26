#define DEBUG 1

/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-27 00:19:34
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

int N, K;
int a[100];
int ans = 0;

int main()
{
  cin >> N >> K;
  for (auto i = 0; i < N; i++)
  {
    cin >> a[i];
  }
  for (auto l = 0; l < K; l++)
  {
    for (auto r = 0; r < K - l; r++)
    {
      if (l + r > N)
      {
        continue;
      }
      int now = 0;
      int d = K - l - r;
      vector<int> V;
      for (auto i = 0; i < l; i++)
      {
        now += a[i];
        V.push_back(a[i]);
      }
      for (auto i = N - r; i < N; i++)
      {
        now += a[i];
        V.push_back(a[i]);
      }
      sort(V.begin(), V.end());
      for (auto i = 0; i < d; i++)
      {
        if (i >= (int)V.size())
        {
          break;
        }
        if (V[i] >= 0)
        {
          break;
        }
        now -= V[i];
      }
      ans = max(ans, now);
    }
  }
  cout << ans << endl;
}