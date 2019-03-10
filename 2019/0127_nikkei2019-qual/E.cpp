/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 1/27/2019, 9:45:49 PM
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

bool same(int a, int b)
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
ll X[100010];
int A[100010];
int B[100010];
ll Y[100010];
typedef tuple<ll, int, int> E;
vector<E> V;
typedef tuple<ll, int, int, bool> F;
vector<F> W;
ll X_sum = 0;

int main()
{
  init();
  cin >> N >> M;
  for (auto i = 0; i < N; i++)
  {
    cin >> X[i];
    X_sum += X[i];
  }
  int ans = 0;
  for (auto i = 0; i < M; i++)
  {
    cin >> A[i] >> B[i] >> Y[i];
    A[i]--;
    B[i]--;
    V.push_back(E(Y[i], A[i], B[i]));
  }
  sort(V.begin(), V.end());
  ll maxi_Y = 0;
  for (auto x : V)
  {
    ll cost = get<0>(x);
    int v = get<1>(x);
    int w = get<2>(x);
    maxi_Y = max(cost, maxi_Y);
    if (!same(v, w))
    {
      unite(v, w);
      W.push_back(F(cost, v, w, true));
    }
    else if (X_sum < cost)
    {
      ans++;
    }
    else
    {
      W.push_back(F(cost, v, w, false));
    }
  }
  if (maxi_Y <= X_sum)
  {
    cout << ans << endl;
    return 0;
  }
  
}