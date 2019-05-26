#define DEBUG 1

/**
 * File    : E2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-27 00:40:23
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

int N, Q;
typedef tuple<ll, int, ll> event; // 0: 壁が置かれる。 1: 半直線発射。 2: 壁が取り除かれる。
vector<event> V;
multiset<ll> S; // 壁が置かれた座標。

int main()
{
  cin >> N >> Q;
  for (auto i = 0; i < N; i++)
  {
    ll s, t, x;
    cin >> s >> t >> x;
    V.push_back(event(s - x, 0, x));
    V.push_back(event(t - x, 2, x));
  }
  for (auto i = 0; i < Q; i++)
  {
    ll d;
    cin >> d;
    V.push_back(event(d, 1, 0));
  }
  sort(V.begin(), V.end());
  for (auto e : V)
  {
    ll time, dist;
    int c;
    tie(time, c, dist) = e;
#if DEBUG == 1
    cerr << "time = " << time << ", c = " << c << ", dist = " << dist << endl;
#endif
    if (c == 0)
    {
      S.insert(dist);
    }
    else if (c == 1)
    {
      if (S.empty())
      {
        cout << -1 << endl;
      }
      else
      {
        cout << *S.begin() << endl;
      }
    }
    else
    {
      S.erase(S.find(dist));
    }
  }
}