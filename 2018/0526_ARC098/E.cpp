/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-26 21:42:14
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

const int UF_SIZE = 2010;
int union_find[UF_SIZE];
int cnt[UF_SIZE];

void init()
{
  for (auto i = 0; i < UF_SIZE; i++)
  {
    union_find[i] = i;
    cnt[i] = 1;
  }
}

int root(int a)
{
  if (a == union_find[a])
    return a;
  return (union_find[a] = root(union_find[a]));
}

bool same(int a, int b)
{
  return root(a) == root(b);
}

void unite(int a, int b)
{
  union_find[root(a)] = root(b);
  cnt[root(b)] += cnt[root(a)];
}

int union_size(int a)
{
  return cnt[root(a)];
}

bool isroot(int a)
{
  return root(a) == a;
}

typedef pair<int, int> P;

int N;
int K;
int Q;
int A[2010];
vector<P> V;

int main()
{
  cin >> N >> K >> Q;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
    V.push_back(P(A[i], i));
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  int ans = 1000000007;
  for (auto i = 0; i < N; i++)
  {
    bool visited[2010];
    fill(visited, visited + 2010, false);
    int sel = 0;
    int X = V[i].first;
    cerr << "X = " << X << endl;
    for (auto j = i; j < N; j++)
    {
      int k = V[j].second;
      visited[k] = true;
      if (k - 1 >= 0 && visited[k - 1])
      {
        unite(k, k - 1);
      }
      if (k + 1 < N && visited[k + 1])
      {
        unite(k, k + 1);
      }
      cerr << "union_size(" << k << ") = " << union_size(k) << endl;
      if (union_size(k) >= K)
      {
        sel++;
        if (sel == Q)
        {
          int Y = V[j].second;
          ans = min(ans, X - Y);
          break;
        }
      }
    }
  }
  cout << ans << endl;
}