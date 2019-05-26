#define DEBUG 1

/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-26 21:31:42
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
ll S[200010], T[200010], X[200010];
ll D[200010];
int ans[200010];
typedef tuple<ll, ll, ll, int> K;
vector<K> KK;
typedef tuple<ll, int, int> info;
priority_queue<info, vector<info>, greater<info>> P;

int main()
{
  cin >> N >> Q;
  for (auto i = 0; i < N; i++)
  {
    cin >> S[i] >> T[i] >> X[i];
    KK.push_back(K(X[i], S[i], T[i], i));
  }
  sort(KK.begin(), KK.end());
  for (auto i = 0; i < Q; i++)
  {
    cin >> D[i];
  }
  for (auto i = 0; i < N; i++)
  {
    ll x = get<0>(KK[i]);
    ll s = get<1>(KK[i]);
    ll t = get<2>(KK[i]);
    int ind = get<3>(KK[i]);
    P.push(info(s - x, ind, 0));
    P.push(info(t - x, ind, 1));
  }
  int ind = 0;
  set<int> S;
  fill(ans, ans + Q, -1);
  while (!P.empty())
  {
    info x = P.top();
    P.pop();
    ll next_t = get<0>(x);
    int point = get<1>(x);
    bool start = (get<2>(x) == 0);
#if DEBUG == 1
    cerr << "next_t = " << next_t << endl;
#endif
    while (next_t > D[ind])
    {
      int a = -1;
      if (S.empty())
      {
        a = -1;
      }
      else
      {
        a = *S.begin();
      }
      ans[ind] = a;
#if DEBUG == 1
      cerr << "D[" << ind << "] = " << D[ind] << ", ans[" << ind << "] = " << ans[ind] << endl;
#endif
      ind++;
      if (ind == Q)
      {
        goto EXIT;
      }
    }
    if (start)
    {
      S.insert(point);
#if DEBUG == 1
      cerr << "insert: " << point << endl;
#endif
    }
    else
    {
      S.erase(S.find(point));
#if DEBUG == 1
      cerr << "erase: " << point << endl;
#endif
    }
  }
EXIT:
  for (auto i = 0; i < Q; i++)
  {
    if (ans[i] == -1)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << X[ans[i]] << endl;
    }
  }
}