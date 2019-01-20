/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 1/20/2019, 9:07:59 PM
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

int N, K;
int t[100010];
ll d[100010];

typedef tuple<ll, int> sushi;
vector<sushi> V;
priority_queue<sushi, vector<sushi>, greater<sushi>> Q;
int cnt[100010];

int main()
{
  cin >> N >> K;
  for (auto i = 0; i < N; i++)
  {
    cin >> t[i] >> d[i];
    t[i]--;
    V.push_back(sushi(d[i], t[i]));
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  fill(cnt, cnt + N, 0);
  ll ans = 0;
  ll tans = 0;
  for (auto i = 0; i < K; i++)
  {
    ll cost = get<0>(V[i]);
    int val = get<1>(V[i]);
    tans += cost;
    cnt[val]++;
    Q.push(V[i]);
  }
  ll v = 0;
  for (auto i = 0; i < N; i++)
  {
    if (cnt[i] > 0)
    {
      v++;
    }
  }
  ans = tans + v * v;
  for (auto i = K; i < N; i++)
  {
    ll cost = get<0>(V[i]);
    int val = get<1>(V[i]);
    if (cnt[val] == 0)
    {
      while (!Q.empty())
      {
        ll cost_q = get<0>(Q.top());
        int val_q = get<1>(Q.top());
        Q.pop();
        if (cnt[val_q] >= 2)
        {
          cnt[val_q]--;
          tans -= cost_q;
          cnt[val]++;
          tans += cost;
          v++;
          ans = max(ans, tans + v * v);
          break;
        }
      }
    }
  }
  cout << ans << endl;
}