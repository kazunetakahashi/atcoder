#define DEBUG 1

/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-25 21:27:40
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

class BIT
{ // index starts at 1.
public:
  int N;
  ll *data;

  BIT()
  {
  }

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
  {
    return sum(b) - sum(a);
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

int Q;
typedef tuple<char, ll, ll> query;
vector<query> V;
char c;
ll B = 0;
map<ll, int> M;
vector<ll> W;
priority_queue<ll> L;
priority_queue<ll, vector<ll>, greater<ll>> R;
BIT bit;

void merge(ll a, ll b)
{
  ll x = L.top();
  ll y = R.top();
  if (a <= x)
  {
    L.push(a);
  }
  else if (a >= y)
  {
    R.push(a);
  }
  else
  {
    L.push(a);
  }
  while (L.size() > R.size())
  {
    ll t = L.top();
    L.pop();
    R.push(t);
  }
  while (L.size() < R.size())
  {
    ll t = R.top();
    R.pop();
    L.push(t);
  }
  B += b;
  bit.add(M[a], a);
}

void flush()
{
  ll val = L.top();
  ll ans = B;
  ans -= bit.sum(M[val]);
  ans += bit.sum(M[val], W.size());
  cout << val << " " << ans << endl;
}

int main()
{
  cin >> Q;
  L.push(-1000000000000LL);
  R.push(1000000000000LL);
  for (auto i = 0; i < Q; i++)
  {
    cin >> c;
    if (c == '1')
    {
      ll a, b;
      cin >> a >> b;
      V.push_back(query(c, a, b));
    }
    else
    {
      V.push_back(query(c, 0, 0));
    }
  }
  for (auto i = 0; i < Q; i++)
  {
    if (get<0>(V[i]) == '1')
    {
      ll a = get<1>(V[i]);
      W.push_back(a);
    }
  }
  sort(W.begin(), W.end());
  for (auto i = 0; i < (int)W.size(); i++)
  {
    M[W[i]] = i + 1;
  }
  bit = BIT(W.size());
  for (auto i = 0; i < Q; i++)
  {
    if (get<0>(V[i]) == '1')
    {
      merge(get<1>(V[i]), get<2>(V[i]));
    }
    else
    {
      flush();
    }
  }
}