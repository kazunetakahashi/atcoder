#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2/16/2019, 9:07:46 PM
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

int N, M;
int A[10];
int need[10] = {100, 2, 5, 5, 4, 5, 6, 3, 7, 6};
map<int, int> X;
vector<vector<int>> Y;
vector<vector<int>> W;

void dfs(vector<int> L, int R)
{
#if DEBUG == 1
  cerr << "dfs(" << L.size() << ", " << R << ")" << endl;
  cerr << "L: ";
  for (auto x : L)
  {
    cerr << x << " ";
  }
  cerr << endl;
#endif
  if (R == 0)
  {
    Y.push_back(L);
  }
  else
  {
    for (auto x : X)
    {
      int cost = x.first;
      if ((L.empty() || cost >= L[L.size() - 1]) && cost <= R)
      {
        L.push_back(cost);
        dfs(L, R - cost);
        L.pop_back();
      }
    }
  }
}

ll max_score(vector<int> L)
{
  vector<int> F;
  for (auto x : L)
  {
    F.push_back(X[x]);
  }
  sort(F.begin(), F.end());
  reverse(F.begin(), F.end());
  string ans = "";
  for (auto i = 0; i < min(15, (int)F.size()); i++)
  {
    ans = ans + to_string(F[i]);
  }
#if DEBUG == 1
  cerr << "max_score: " << ans << endl;
#endif
  return stoll(ans);
}

void represent(vector<int> L)
{
  vector<int> F;
  for (auto x : L)
  {
    F.push_back(X[x]);
  }
  sort(F.begin(), F.end());
  reverse(F.begin(), F.end());
  for (auto i = 0; i < (int)F.size(); i++)
  {
    cout << F[i];
  }
}

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    cin >> A[i];
    int n = need[A[i]];
    if (X.find(n) == X.end())
    {
      X[n] = A[i];
    }
    else
    {
      X[n] = max(X[n], A[i]);
    }
  }
  int cnt = 0;
  int cost = (*X.begin()).first;
  string base = to_string((*X.begin()).second);
  while (N > 500)
  {
    N -= cost;
    cnt++;
  }
  if (cost == 2 && N % 2 == 0)
  {
    while (N > 0)
    {
      N -= cost;
      cnt++;
    }
  }
  else if (cost == 2)
  {
    auto it = X.begin();
    while ((*it).first % 2 == 0)
    {
      it++;
    }
    cout << (*it).second;
    N -= (*it).first;
    while (N > 0)
    {
      N -= cost;
      cnt++;
    }
  }
  else
  {
    vector<int> V = {};
#if DEBUG == 1
    cerr << "N = " << N << endl;
#endif
    dfs(V, N);
    int maxi = 0;
    for (auto v : Y)
    {
      maxi = max((int)v.size(), maxi);
    }
#if DEBUG == 1
    cerr << "maxi = " << maxi << endl;
#endif
    for (auto v : Y)
    {
      if ((int)v.size() == maxi)
      {
#if DEBUG == 1
        cerr << "v: ";
        for (auto x : v)
        {
          cerr << x << " ";
        }
        cerr << endl;
#endif
        W.push_back(v);
      }
    }
    ll maxi_score = 0;
    vector<int> ans;
    for (auto v : W)
    {
      ll m_s = max_score(v);
      if (maxi_score < m_s)
      {
        maxi_score = m_s;
        ans = v;
      }
      else if (maxi_score == m_s)
      {
        assert(false);
      }
    }
    represent(ans);
  }
  for (auto i = 0; i < cnt; i++)
  {
    cout << base;
  }
  cout << endl;
}