#define DEBUG 1

/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 4/7/2019, 12:27:14 AM
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

ll X[3];
ll K;
ll A[3][1010];
vector<ll> ans;

int main()
{
  for (auto i = 0; i < 3; i++)
  {
    cin >> X[i];
  }
  cin >> K;
  for (auto i = 0; i < 3; i++)
  {
    for (auto j = 0; j < X[i]; j++)
    {
      cin >> A[i][j];
    }
  }
  for (auto i = 0; i < 3; i++)
  {
    sort(A[i], A[i] + X[i]);
    reverse(A[i], A[i] + X[i]);
  }
  for (auto i = 0; i < X[0]; i++)
  {
    if (i + 1 > K)
    {
      break;
    }
    for (auto j = 0; j < X[1]; j++)
    {
      if ((i + 1) * (j + 1) > K)
      {
        break;
      }
      for (auto k = 0; k < X[2]; k++)
      {
        if ((i + 1) * (j + 1) * (k + 1) > K)
        {
          break;
        }
        ans.push_back(A[0][i] + A[1][j] + A[2][k]);
      }
    }
  }
  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  for (auto i = 0; i < K; i++)
  {
    cout << ans[i] << endl;
  }
}