#define DEBUG 1

/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 3/16/2019, 10:14:01 PM
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

int N;
ll A, B;
vector<ll> ans;

void flush()
{
  int S = ans.size();
  for (auto i = 0; i < S; i++)
  {
    cout << ans[i];
    if (i < S - 1)
    {
      cout << " ";
    }
    else
    {
      cout << endl;
    }
  }
}

vector<ll> make(int n)
{
  if (n == 1)
  {
    return {0, 1};
  }
  vector<ll> V = make(n - 1);
  int S = V.size();
  vector<ll> W;
  for (auto i = 0; i < S / 2; i++)
  {
    W.push_back(V[i]);
  }
  for (auto i = S / 2 - 1; i >= 0; i--)
  {
    W.push_back(V[i] + (1LL << (n - 1)));
  }
  for (auto i = S - 1; i >= S / 2; i--)
  {
    W.push_back(V[i] + (1LL << (n - 1)));
  }
  for (auto i = S / 2; i < S; i++)
  {
    W.push_back(V[i]);
  }
  return W;
}

void solve(int i)
{
  vector<ll> V = make(N);
  for (auto i = 0; i < (int)V.size(); i++)
  {
    ll x = V[i];
    ll y = (x << i);
    ll mod = y % (1LL << N);
    ll k = (y >> N);
    V[i] = mod + k;
    ans.push_back(A ^ V[i]);
  }
  flush();
}

int main()
{
  /*
#if DEBUG == 1
  cin >> N;
  cerr << "make(" << N << ")" << endl;
  vector<ll> V = make(N);
  for (auto x : V)
  {
    cerr << x << " ";
  }
  cerr << endl;
#endif
  */
  cin >> N >> A >> B;
  ll x = (A ^ B);
  for (auto i = 0; i < 20; i++)
  {
    if ((1LL << i) == x)
    {
      cout << "YES" << endl;
      solve(i);
      assert(false);
      return 0;
    }
  }
  cout << "NO" << endl;
}