/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-9-15 21:34:24
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
string s;
int L[200010];
set<int> S[200010][2];
bool ok[200010];

int main()
{
  cin >> N >> M >> s;
  for (auto i = 0; i < M; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    S[b][L[a]].insert(a);
    S[a][L[b]].insert(b);
  }
  for (auto i = 0; i < N; i++)
  {
    if (s[i] == 'A')
    {
      L[i] = 0;
    }
    else
    {
      L[i] = 1;
    }
  }
  fill(ok, ok + N, true);
  queue<int> Q;
  for (auto i = 0; i < N; i++)
  {
    if (S[i][0].empty() || S[i][1].empty())
    {
      Q.push(i);
    }
  }
  while (!Q.empty())
  {
    int now = Q.front();
    Q.pop();
    if (!ok[now])
    {
      continue;
    }
    ok[now] = false;
    for (auto k = 0; k < 2; k++)
    {
      if (S[now][k].empty())
      {
        continue;
      }
      for (auto x : S[now][k])
      {
        S[x][L[now]].erase(now);
        if (S[x][L[now]].empty())
        {
          Q.push(x);
        }
      }
    }
  }
  bool first[2] = {false, false};
  for (auto i = 0; i < N; i++)
  {
    if (ok[i])
    {
      cerr << i << " : ok" << endl;
      first[L[i]] = true;
    }
  }
  if (first[0] && first[1])
  {
    cout << "Yes" << endl;
  }
  else
  {
    cout << "No" << endl;
  }
}