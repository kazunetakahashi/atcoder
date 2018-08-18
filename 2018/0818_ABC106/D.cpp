/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 8/18/2018, 9:08:51 PM
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

class BIT
{ // index starts at 1.
public:
  int N;
  ll *data;

  BIT(int n) : N(n)
  {
    data = new ll[N + 1];
    for (auto i = 1; i <= N; ++i)
    {
      data[i] = 0;
    }
  }

  ~BIT()
  {
    delete[] data;
  }

  ll sum(int i)
  { // [1, i]
    ll s = 0;
    while (i > 0)
    {
      s += data[i];
      i -= i & -i;
    }
    return s;
  }

  ll sum(int a, int b)
  { // [a, b)
    return sum(b - 1) - sum(a - 1);
  }

  void add(int i, ll x)
  {
    while (i <= N)
    {
      data[i] += x;
      i += i & -i;
    }
  }

  void add(int i)
  {
    add(i, 1);
  }
};

int N, M, Q;

typedef tuple<int, int> que;

vector<int> seg[510];
vector<que> X[510];
int ans[100010];

int main()
{
  cin >> N >> M >> Q;
  for (auto i = 0; i < M; i++)
  {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    seg[r].push_back(l);
  }
  for (auto i = 0; i < Q; i++)
  {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    X[r].push_back(que(l, i));
  }
  BIT bit(510);
  for (auto r = 0; r < N; r++)
  {
    for (auto x : seg[r])
    {
      cerr << "l = " << x << endl;
      bit.add(x);
    }
    for (auto x : X[r])
    {
      int l = get<0>(x);
      int ind = get<1>(x);
      ans[ind] = bit.sum(l, r + 1);
    }
  }
  for (auto i = 0; i < Q; i++)
  {
    cout << ans[i] << endl;
  }
}