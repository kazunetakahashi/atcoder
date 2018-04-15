/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-15 21:25:15
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

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

string S;
int N;
bool par[20010];
bool used[20010];

bool solve()
{
  N = S.size();
  int cnt = 0;
  for (auto i = 0; i < N; i++)
  {
    par[i] = (S[i] == '(');
    if (par[i])
    {
      ++cnt;
    }
  }
  if (cnt != N/2)
  {
    return false;
  }
  fill(used, used + N, false);
  int c[2] = {0, 0};
  int now = 0;
  while (now < N && (c[0] < N / 4 || c[1] < N / 4))
  {
    cerr << now << endl;
    assert(c[0] >= c[1]);
    if (c[0] == N/4)
    {
      if (!par[now])
      {
        used[now] = true;
        c[1]++;
      }
    }
    else if (c[0] == c[1])
    {
      if (par[now])
      {
        used[now] = true;
        c[0]++;
      }
    }
    else
    {
      used[now] = true;
      c[par[now]]++;
    }
    now++;
  }
  if (c[0] < N/4 || c[1] < N/4)
  {
    return false;
  }
  c[0] = c[1] = 0;
  now = 0;
  while (now < N && (c[0] < N / 4 || c[1] < N / 4))
  {
    if (used[now])
    {
      continue;
    }
    assert(c[0] >= c[1]);
    if (c[0] == N/4)
    {
      if (par[now])
      {
        used[now] = true;
        c[1]++;
      }
    }
    else if (c[0] == c[1])
    {
      if (!par[now])
      {
        used[now] = true;
        c[0]++;
      }
    }
    else
    {
      used[now] = true;
      c[1 - (int)par[now]]++;
    }
    now++;
  }
  if (c[0] < N/4 || c[1] < N/4)
  {
    return false;
  }
  return true;
}

int main()
{
  int Q;
  cin >> Q;
  for (auto i = 0; i < Q; i++)
  {
    cin >> S;
    cout << (solve() ? "Yes" : "No") << endl;
  }
}