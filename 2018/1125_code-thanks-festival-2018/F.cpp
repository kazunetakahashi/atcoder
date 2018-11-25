/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 11/25/2018, 12:58:28 PM
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

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int N, M, K;
int P[310];
int root = 0;
vector<int> children[310];
int cnt_c[310];
int cnt_sum[310];
int S[310];
vector<int> T[310];
bool used[310];
bool ok = true;
vector<int> ans;
int mini = 0;

int calc_S(int v)
{
  if (S[v] != -1)
  {
    return S[v];
  }
  if (v == root)
  {
    return S[v] = 1;
  }
  return S[v] = calc_S(P[v]) + 1;
}

void flush()
{
  if (ok)
  {
    assert((int)ans.size() == M);
    for (auto i = 0; i < M; i++)
    {
      cout << ans[i] + 1;
      if (i < M - 1)
      {
        cout << " ";
      }
    }
  }
  else
  {
    cout << -1 << endl;
  }
}

int calc_c(int v)
{
  cnt_c[v] = 1;
  for (auto x : children[v])
  {
    cnt_c[v] += calc_c(x);
  }
  return cnt_c[v];
}

int calc_sum(int v)
{
  cnt_sum[v] = cnt_c[v];
  for (auto x : children[v])
  {
    cnt_sum[v] += calc_sum(x);
  }
  return cnt_sum[v];
}

int calc_mini(int remain)
{
  mini = 0;
  for (auto i = 0; i < 310; i++)
  {
    if (remain <= 0)
    {
      break;
    }
    int x = min((int)T[i].size(), remain);
    mini += i * x;
    remain -= x;
  }
  return mini;
}

void init()
{
  fill(S, S + N, -1);
  for (auto i = 0; i < 310; i++)
  {
    T[i].clear();
  }
  for (auto i = 0; i < N; i++)
  {
    T[calc_S(i)].push_back(i);
  }
  calc_c(root);
  calc_sum(root);
  calc_mini(M - (int)ans.size());
}

void make_used(int v)
{
  used[v] = true;
  for (auto x : children[v])
  {
    make_used(x);
  }
}

bool erasable(int v)
{
  int cost = S[v];
  if (P[v] == -1)
  {
    if (K == 1 && (int)ans.size() == M - 1)
    {
      ans.push_back(v);
      return true;
    }
    return false;
  }
  ans.push_back(v);
  auto it = children[P[v]].begin();
  while (it != children[P[v]].end())
  {
    if (*it == v)
    {
      children[P[v]].erase(it);
      break;
    }
  }
  init();
  /*
  cerr << "cnt_c[" << root << "] = " << cnt_c[root] << endl;
  cerr << "M - ans.size() - 1 = " << M - ans.size() - 1 << endl;
  cerr << "cost = " << cost << endl;
  cerr << "cnt_sum[" << root << "] = " << cnt_sum[root] << endl;
  cerr << "mini = " << mini << endl;
  */
  if ((int)ans.size() == M)
  {
    if (cost == K)
    {
      return true;
    }
  }
  else if (cnt_c[root] >= M - (int)ans.size() && mini <= K - cost && K - cost <= cnt_sum[root])
  {
    K -= cost;
    make_used(v);
    return true;
  }
  children[P[v]].push_back(v);
  it = ans.end();
  it--;
  ans.erase(it);
  return false;
}

int main()
{
  cin >> N >> M >> K;
  for (auto i = 0; i < N; i++)
  {
    cin >> P[i];
    P[i]--;
  }
  for (auto i = 0; i < N; i++)
  {
    if (P[i] == -1)
    {
      root = i;
    }
    else
    {
      children[P[i]].push_back(i);
    }
  }
  init();
  fill(used, used + N, false);
  for (auto i = 0; i < M; i++)
  {
    bool valid = false;
    for (auto j = 0; j < N; j++)
    {
      if (used[j])
      {
        continue;
      }
      if (erasable(j))
      {
        cerr << "erase: " << j << endl;
        valid = true;
        break;
      }
    }
    if (!valid)
    {
      ok = false;
      break;
    }
  }
  flush();
}