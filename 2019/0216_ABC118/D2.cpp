#define DEBUG 1

/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 2/16/2019, 10:46:37 PM
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

int N;
int M;
map<int, int> X;
int H[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
typedef vector<int> num;
vector<num> Y;
vector<num> Z;

void dfs(num V, int used, int R)
{
  if (R == 0)
  {
    Y.push_back(V);
  }
  else
  {
    for (auto x : X)
    {
      int cost = x.first;
      int value = x.second;
      if ((V.empty() || used <= value) && R >= cost)
      {
        V[value]++;
        dfs(V, value, R - cost);
        V[value]--;
      }
    }
  }
}

ll max_value(num V)
{
  string ans = "";
  for (auto i = 9; i >= 0; i--)
  {
    for (auto j = 0; j < V[i]; j++)
    {
      ans += to_string(i);
      if (ans.size() > 12)
      {
        break;
      }
    }
    if (ans.size() > 12)
    {
      break;
    }
  }
  return stoll(ans);
}

void flush(num V)
{
  for (auto i = 9; i >= 0; i--)
  {
    for (auto j = 0; j < V[i]; j++)
    {
      cout << i;
    }
  }
  cout << endl;
}

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    int A;
    cin >> A;
    int cost = H[A];
    if (X.find(cost) == X.end())
    {
      X[cost] = A;
    }
    else
    {
      X[cost] = max(X[cost], A);
    }
  }
  vector<int> V(10, 0);
  int mini_cost = (*X.begin()).first;
  int mini_value = (*X.begin()).second;
  while (N > 100)
  {
    V[mini_value]++;
    N -= mini_cost;
  }
  dfs(V, 0, N);
  int maxi_digit = 0;
  for (auto v : Y)
  {
    int digit = 0;
    for (auto i = 0; i < 10; i++)
    {
      digit += v[i];
    }
    maxi_digit = max(digit, maxi_digit);
  }
  for (auto v : Y)
  {
    int digit = 0;
    for (auto i = 0; i < 10; i++)
    {
      digit += v[i];
    }
    if (digit == maxi_digit)
    {
      Z.push_back(v);
    }
  }
  ll maxi = 0;
  num ans;
  for (auto x : Z)
  {
    ll t_maxi = max_value(x);
    if (maxi < t_maxi)
    {
      maxi = t_maxi;
      ans = x;
    }
  }
  flush(ans);
}