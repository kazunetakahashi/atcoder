#define DEBUG 1

/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-3-24 22:42:41
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
const ll MOD = 1000000007;

int N;
set<string> forbid;
string chars[4] = {"A", "G", "C", "T"};
typedef tuple<int, string> key;
map<key, ll> M;

void make(string S)
{
  if (S.size() < 4)
  {
    for (auto i = 0; i < 4; i++)
    {
      make(S + chars[i]);
    }
  }
  else
  {
    string T = S;
    for (auto i = 0; i < 4; i++)
    {
      if (i < 3)
      {
        swap(T[i], T[i + 1]);
      }
    }
    for (auto i = 0; i < 2; i++)
    {
      if (T.substr(i, 3) == "AGC")
      {
        forbid.insert(S);
        return;
      }
    }
  }
}

bool ok(string S)
{
  return (forbid.find(S) == forbid.end());
}

ll dfs(int x, string S)
{
  if (M.find(key(x, S)) != M.end())
  {
    return M[key(x, S)];
  }
  if (x == N)
  {
    return 1;
  }
  ll ans = 0;
  for (auto i = 0; i < 4; i++)
  {
    string T = S + chars[i];
    if (ok(T))
    {
      ans += dfs(x + 1, T.substr(1, 3));
      ans %= MOD;
    }
  }
  return ans;
}

int main()
{
  cin >> N;
  make("");
#if DEBUG == 1
  for (auto x : forbid)
  {
    cerr << x << endl;
  }
#endif
  cout << dfs(0, "TTT") << endl;
}