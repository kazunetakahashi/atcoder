#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-26 21:13:56
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
int X[100];

int _solve(vector<int> V, int k)
{
  int ans = 0;
  for (auto i = 0; i <= min((int)V.size(), k); i++)
  {
    vector<int> W;
    for (auto j = 0; j < i; j++)
    {
      W.push_back(V[j]);
    }
    sort(W.begin(), W.end());
    int n = k - i;
    int ind = 0;
    for (auto j = 0; j < min(n, (int)W.size()); j++)
    {
      if (W[j] < 0)
      {
        ind++;
      }
    }
    int t = 0;
    for (auto j = ind; j < (int)W.size(); j++)
    {
      t += W[j];
    }
    ans = max(ans, t);
  }
  return ans;
}

int solve(vector<int> V, vector<int> W)
{
  int ans = 0;
  for (auto i = 0; i <= K; i++)
  {
    ans = max(ans, _solve(V, i) + _solve(W, K - i));
  }
  return ans;
}

int main()
{
  cin >> N >> K;
  for (auto i = 0; i < N; i++)
  {
    cin >> X[i];
  }
  int ans = 0;
  for (auto i = 0; i <= K; i++)
  {
    vector<int> V, W;
    for (auto j = 0; j < i; j++)
    {
      V.push_back(X[j]);
    }
    for (auto j = K - 1; j >= i; j--)
    {
      W.push_back(X[j]);
    }
    ans = max(ans, solve(V, W));
  }
  cout << ans << endl;
}