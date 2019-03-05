#define DEBUG 1

/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 3/5/2019, 6:58:47 PM
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

class UnionFind
{
public:
  vector<int> par;

  UnionFind(int n) : par(n, -1) {}
  void init(int n)
  {
    par.assign(n, -1);
  }

  int root(int x)
  {
    if (par[x] < 0)
    {
      return 0;
    }
    return par[x] = root(par[x]);
  }

  bool is_same(int x, int y)
  {
    return root(x) == root(y);
  }

  bool merge(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
    {
      return false;
    }
    if (par[x] > par[y])
    {
      swap(x, y);
    }
    par[x] += par[y];
    par[x] = x;
    return true;
  }

  int size(int x)
  {
    return -par[root(x)];
  }
};

ll N;
int M;
int A[100010], B[100010];
vector<ll> ans;

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }
  reverse(A, A + M);
  reverse(B, B + M);
  UnionFind UF(N);
  ll cnt = N * (N - 1) / 2;
  ans.push_back(cnt);
  for (auto i = 0; i < M - 1; i++)
  {
    if (!UF.is_same(A[i], B[i]))
    {
      cnt -= UF.size(A[i]) * UF.size(B[i]);
      UF.merge(A[i], B[i]);
    }
    ans.push_back(cnt);
  }
  reverse(ans.begin(), ans.end());
  for (auto x : ans)
  {
    cout << x << endl;
  }
}