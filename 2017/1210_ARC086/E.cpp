/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-27 14:50:03
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
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define DEBUG 1 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;

const int MAX_SIZE = 1000010;
const long long MOD = 1000000007;

long long inv[MAX_SIZE];
long long fact[MAX_SIZE];
long long factinv[MAX_SIZE];

void init() {
  inv[1] = 1;
  for (int i=2; i<MAX_SIZE; i++) {
    inv[i] = ((MOD - inv[MOD%i]) * (MOD/i))%MOD;
  }
  fact[0] = factinv[0] = 1;
  for (int i=1; i<MAX_SIZE; i++) {
    fact[i] = (i * fact[i-1])%MOD;
    factinv[i] = (inv[i] * factinv[i-1])%MOD;
  }
}

long long C(int n, int k) {
  if (n >=0 && k >= 0 && n-k >= 0) {
    return ((fact[n] * factinv[k])%MOD * factinv[n-k])%MOD;
  }
  return 0;
}

long long power(long long x, long long n) {
  if (n == 0) {
    return 1;
  } else if (n%2 == 1) {
    return (x * power(x, n-1)) % MOD;
  } else {
    long long half = power(x, n/2);
    return (half * half) % MOD;
  }
}

long long gcm(long long a, long long b) {
  if (a < b) {
    return gcm(b, a);
  }
  if (b == 0) return a;
  return gcm(b, a%b);
}

int N;
int parent[200010];
vector<int> children[200010];
int depth[200010];
ll dep[200010];
vector<deque<vector<ll>>> DP;
vector<deque<vector<ll>>>::iterator itr[200010];

vector<ll> first = {1, 1, 0};

vector<deque<vector<ll>>>::iterator make(int v)
{
  if (children[v].empty())
  {
    DP[v].push_front(first);
    itr[v] = DP.begin() + v;
    return itr[v];
  }
  auto it = make(children[v][0]);
  int len = 0;
  for (auto i = 1; i < (int)children[v].size(); i++)
  {
    auto tit = make(children[v][0]);
    if (it->size() < tit->size())
      swap(it, tit);
    len = max(len, (int)(tit->size()));
    for (auto j = 0; j < (int)(tit->size()); j++)
    {
      ll zero = ((*it)[j][0] * (*tit)[j][0]) % MOD;
      ll one = ((*it)[j][1] * (*tit)[j][0]) % MOD;
      one += ((*it)[j][0] * (*tit)[j][1]) % MOD;
      one %= MOD;
      ll sum1 = ((*it)[j][0] + (*it)[j][1] + (*it)[j][2]) % MOD;
      ll sum2 = ((*tit)[j][0] + (*tit)[j][1] + (*tit)[j][2]) % MOD;
      ll two = ((sum1 * sum2) % MOD + MOD - zero + MOD - one) % MOD;
      (*it)[j][0] = zero;
      (*it)[j][1] = one;
      (*it)[j][2] = two;
    }
  }
  for (auto i = 0; i < len; i++)
  {
    (*it)[i][0] += (*it)[i][2];
    (*it)[i][0] %= MOD;
    (*it)[i][2] = 0;
  }
  (*it).push_front(first);
  itr[v] = it;
  return itr[v];
}

int main()
{
  cin >> N;
  parent[0] = -1;
  for (auto i = 1; i <= N; i++)
  {
    cin >> parent[i];
    children[parent[i]].push_back(i);
  }
  DP = vector<deque<vector<ll>>>(N + 1);
  depth[0] = 0;
  queue<int> Q;
  Q.push(0);
  while (!Q.empty())
  {
    int now = Q.front();
    Q.pop();
    for (auto x : children[now])
    {
      depth[x] = depth[now] + 1;
#if DEBUG == 1
      //cerr << "depth[" << x << "] = " << depth[x] << endl;
#endif
      Q.push(x);
    }
  }
  for (auto i = 0; i < N + 1; i++)
  {
    dep[depth[i]]++;
  }
  auto ans = *make(0);
  ll res = 0;
  for (auto i = 0; i < (int)ans.size(); i++)
  {
    #if DEBUG == 1
    cerr << "ans[" << i << "][1] = " << ans[i][1] << ", dep[" << i << "] = " << dep[i] << endl;
    #endif
    res += (ans[i][1] * power(2, N + 1 - dep[i])) % MOD;
    res %= MOD;
  }
  cout << res << endl;
}