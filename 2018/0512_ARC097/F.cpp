/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-12 22:17:51
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
#include <chrono>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int N;
int x[100010];
int y[100010];
string S;
vector<int> T[100010];
vector<int> V[100010];
int root = -1;
int parent[100010];
int parent2[100010];
bool need[100010];
bool del[100010];
int maxi = 0;

int dfs(int v)
{
  int ans = (need[v] ? 1 : 0);
  vector<int> X;
  for (auto e : V[v])
  {
    if (e == parent[v])
    {
      continue;
    }
    else
    {
      parent[e] = v;
      X.push_back(dfs(e));
    }
  }
  if ((int)X.size() == 0)
  {
    return ans;
  }
  else if ((int)X.size() == 1)
  {
    ans += X[0];
    maxi = max(maxi, ans);
    return ans;
  }
  else
  {
    sort(X.begin(), X.end());
    reverse(X.begin(), X.end());
    ans += X[0] + X[1];
    maxi = max(maxi, ans);
    return ans - X[1];
  }
}

bool dfs2(int v)
{
  cerr << "v = " << v << endl;
  bool ans = (S[v] == 'B');
  for (auto e : V[v])
  {
    if (e == parent2[v])
    {
      continue;
    }
    else
    {
      parent2[e] = v;
      ans = (dfs2(e) && ans);
    }
  }
  del[v] = ans;
  if (del[v])
  {
    cerr << "del[" << v << "]" << endl;
  }
  return ans;
}

int main()
{
  int N;
  cin >> N;
  for (auto i = 0; i < N - 1; i++)
  {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
    T[x[i]].push_back(y[i]);
    T[y[i]].push_back(x[i]);
  }
  cin >> S;
  bool allb = true;
  for (auto i = 0; i < N; i++)
  {
    if (S[i] == 'W')
    {
      allb = false;
      break;
    }
  }
  if (allb)
  {
    cout << 0 << endl;
    return 0;
  }
  for (auto i = 0; i < N; i++)
  {
    if (S[i] == 'W')
    {
      root = i;
      break;
    }
  }
  assert(root >= 0);
  parent2[root] = -1;
  dfs2(root);
  int M = 0;
  for (auto i = 0; i < N - 1; i++)
  {
    if (!del[x[i]] && !del[y[i]])
    {
      V[x[i]].push_back(y[i]);
      V[y[i]].push_back(x[i]);
      M++;
    }
  }
  M++;
  int cost = 0;
  fill(need, need + 100010, false);
  for (auto i = 0; i < N; i++)
  {
    if (del[i])
    {
      continue;
    }
    if ((((int)V[i].size()) % 2 == 0) ^ (S[i] == 'B'))
    {
      cost++;
      need[i] = true;
    }
  }
  // cerr << "cost = " << cost << endl;
  for (auto i = 0; i < N; i++)
  {
    if (!del[i] && S[i] == 'W')
    {
      root = i;
      break;
    }
  }
  assert(root >= 0);
  parent[root] = -1;
  dfs(root);
  cout << 2 * (M - 1) + cost - maxi * 2 << endl;
}