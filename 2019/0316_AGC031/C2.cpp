#define DEBUG 1

/**
 * File    : C2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-29 17:31:56
 * Powered by Visual Studio Code
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <random>
#include <chrono>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

vector<int> ans;

void Yes()
{
  cout << "YES" << endl;
  int M = ans.size();
  for (auto i = 0; i < M; i++)
  {
    cout << ans[i];
    if (i < M - 1)
    {
      cout << " ";
    }
    else
    {
      cout << endl;
    }
  }
  exit(0);
}

void No()
{
  cout << "NO" << endl;
  exit(0);
}

/*
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
*/

// const ll MOD = 1000000007;

int N;

int cnt(int x)
{
  int ans = 0;
  for (auto i = 0; i < 30; i++)
  {
    if (x >> i & 1)
    {
      ans++;
    }
  }
  return ans;
}

void dfs(int A, int B, int mask)
{
  if (cnt(mask) == N - 1)
  {
    ans.push_back(A);
    ans.push_back(B);
    return;
  }
  int ind;
  for (ind = 0; ind < N; ind++)
  {
    if (mask >> ind & 1)
    {
      continue;
    }
    if ((A >> ind & 1) != (B >> ind & 1))
    {
      break;
    }
  }
  int new_mask = mask | 1 << ind;
  int next;
  for (next = 0; next < N; next++)
  {
    if (mask >> next & 1)
    {
      continue;
    }
    break;
  }
  int C = A ^ 1 << next;
  int D = C ^ 1 << ind;
  dfs(A, C, new_mask);
  dfs(D, B, new_mask);
}

int main()
{
  int A, B;
  cin >> N >> A >> B;
  if (cnt(A ^ B) % 2 == 0)
  {
    No();
  }
  else
  {
    dfs(A, B, 0);
    Yes();
  }
}