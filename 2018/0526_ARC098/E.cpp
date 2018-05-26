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

typedef pair<int, int> P;

int N;
int K;
int Q;
int A[2010];
vector<P> V;
bool visited[2010];

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
  fill(visited, visited + 2010, false);
  for (auto i = 0; i < N; i++)
  {
    int Y = V[i].first;
    cerr << "Y = " << Y << endl;
    int k = V[i].second;
    visited[k] = true;
    int left[2010];
    int right[2010];
    int t = -1;
    for (auto j = 0; j < N; j++)
    {
      if (!visited[j])
      {
        t = j;
      }
      left[j] = t;
    }
    t = N;
    for (auto j = N; j >= 0; j--)
    {
      if (!visited[j])
      {
        t = j;
      }
      right[j] = t;
    }
    for (auto j = 0; j < N; j++)
    {
      cerr << j << " : " << left[j] << " " << right[j] << endl;
    }
    BIT bit(N + 1);
    int cnt[2010];
    for (auto j = 0; j <= i; j++)
    {
      cerr << "k = " << k << endl;
      k = V[j].second;
      bit.add(k);
      cnt[k] = bit.sum(left[k] + 1, right[k]);
      cerr << "cnt[" << k << "] = " << cnt[k] << endl;
    }
    int sel = 0;
    for (auto j = i; j >= 0; j--)
    {
      k = V[j].second;
      if (cnt[k] >= K)
      {
        sel++;
        if (sel == Q)
        {
          int X = V[j].first;
          ans = min(ans, X - Y);
          break;
        }
      }
    }
  }
  cout << ans << endl;
}