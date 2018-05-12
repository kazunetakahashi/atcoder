/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-12 21:08:34
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

const int UFSIZE = 100010;
int union_find[UFSIZE];

void init()
{
  for (auto i = 0; i < UFSIZE; i++)
  {
    union_find[i] = i;
  }
}

int root(int a)
{
  if (a == union_find[a])
    return a;
  return (union_find[a] = root(union_find[a]));
}

bool issame(int a, int b)
{
  return root(a) == root(b);
}

void unite(int a, int b)
{
  union_find[root(a)] = root(b);
}

bool isroot(int a)
{
  return root(a) == a;
}

int N, M;
int p[100010];
int x[100010];
int y[100010];

int main()
{
  init();
  cin >> N >> M;
  for (auto i = 0; i < N; i++)
  {
    cin >> p[i];
    p[i]--;
  }
  for (auto i = 0; i < M; i++)
  {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  for (auto i = 0; i < M; i++)
  {
    unite(p[x[i]], p[y[i]]);
  }
  int ans = 0;
  for (auto i = 0; i < M; i++)
  {
    if (issame(i, p[i]))
    {
      ++ans;
    }
  }
  cout << ans << endl;
}