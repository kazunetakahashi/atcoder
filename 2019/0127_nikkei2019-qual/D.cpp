/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 1/27/2019, 9:12:45 PM
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

int N, M;
int A[100010];
int B[100010];
set<int> V[100010];
set<int> W[100010];
int root;
int depth[100010];
int parent[100010];
typedef tuple<int, int, int> T; // v, pa, de
queue<T> Q;

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < N - 1 + M; i++)
  {
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
  }
  for (auto i = 0; i < N - 1 + M; i++)
  {
    V[A[i]].insert(B[i]);
    W[B[i]].insert(A[i]);
  }
  fill(depth, depth + N, -1);
  fill(parent, parent + N, -2);
  int root_cnt = 0;
  for (auto i = 0; i < N; i++)
  {
    if (W[i].empty())
    {
      root_cnt++;
      root = i;
      parent[i] = -1;
    }
  }
  assert(root_cnt == 1);
  Q.push(T(root, -1, 0));
  while (!Q.empty())
  {
    int v = get<0>(Q.front());
    int p = get<1>(Q.front());
    int d = get<2>(Q.front());
    if (depth[v] == -1)
    {
      parent[v] = p;
      depth[v] = d;
      for (auto x : V[v])
      {
        Q.push(T(x, v, d + 1));
      }
    }
    else if (depth[v] < d)
    {
      parent[v] = p;
      depth[v] = d;
    }
  }
  for (auto i = 0; i < N; i++)
  {
    cout << parent[i] + 1 << endl;
  }
}