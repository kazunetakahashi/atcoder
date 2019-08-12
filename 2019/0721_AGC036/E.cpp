#define DEBUG 1
/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 8/12/2019, 7:02:46 PM
 * Powered by Visual Studio Code
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <functional>
#include <random>
#include <chrono>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
using ll = long long;
class mint
{
public:
  static ll MOD;
  ll x;
  mint() : x(0) {}
  mint(ll x) : x(x % MOD) {}
  mint operator-() const { return x ? MOD - x : 0; }
  mint &operator+=(const mint &a)
  {
    if ((x += a.x) >= MOD)
    {
      x -= MOD;
    }
    return *this;
  }
  mint &operator-=(const mint &a) { return *this += -a; }
  mint &operator*=(const mint &a)
  {
    (x *= a.x) %= MOD;
    return *this;
  }
  mint &operator/=(const mint &a)
  {
    mint b{a};
    return *this *= b.power(MOD - 2);
  }
  mint operator+(const mint &a) const { return mint(*this) += a; }
  mint operator-(const mint &a) const { return mint(*this) -= a; }
  mint operator*(const mint &a) const { return mint(*this) *= a; }
  mint operator/(const mint &a) const { return mint(*this) /= a; }
  bool operator<(const mint &a) const { return x < a.x; }
  bool operator==(const mint &a) const { return x == a.x; }
  const mint power(ll N)
  {
    if (N == 0)
    {
      return 1;
    }
    else if (N % 2 == 1)
    {
      return *this * power(N - 1);
    }
    else
    {
      mint half = power(N / 2);
      return half * half;
    }
  }
};
ll mint::MOD = 1e9 + 7;
istream &operator>>(istream &stream, mint &a) { return stream >> a.x; }
ostream &operator<<(ostream &stream, const mint &a) { return stream << a.x; }
class combination
{
public:
  vector<mint> inv, fact, factinv;
  static int MAX_SIZE;
  combination() : inv(MAX_SIZE), fact(MAX_SIZE), factinv(MAX_SIZE)
  {
    inv[1] = 1;
    for (auto i = 2; i < MAX_SIZE; i++)
    {
      inv[i] = (-inv[mint::MOD % i]) * (mint::MOD / i);
    }
    fact[0] = factinv[0] = 1;
    for (auto i = 1; i < MAX_SIZE; i++)
    {
      fact[i] = mint(i) * fact[i - 1];
      factinv[i] = inv[i] * factinv[i - 1];
    }
  }
  mint operator()(int n, int k)
  {
    if (n >= 0 && k >= 0 && n - k >= 0)
    {
      return fact[n] * factinv[k] * factinv[n - k];
    }
    return 0;
  }
};
int combination::MAX_SIZE = 3000010;
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// constexpr double epsilon = 1e-10;
// constexpr ll infty = 1000000000000000LL;
// constexpr int dx[4] = {1, 0, -1, 0};
// constexpr int dy[4] = {0, 1, 0, -1};
void Yes()
{
  cout << "Yes" << endl;
  exit(0);
}
void No()
{
  cout << "No" << endl;
  exit(0);
}

vector<int> count(string const &S)
{
  vector<int> cnt(3, 0);
  for (auto x : S)
  {
    cnt[x - 'A']++;
  }
  return cnt;
}

string reduce(string const &S)
{
  stringstream res{};
  char c{'x'};
  for (auto x : S)
  {
    if (x == c)
    {
      continue;
    }
    else
    {
      res << x;
      c = x;
    }
  }
  return res.str();
}

map<char, char> make_map(string const &S)
{
  vector<int> cnt = count(S);
  vector<tuple<int, char>> V;
  for (auto i = 0; i < 3; i++)
  {
    V.emplace_back(cnt[i], 'A' + i);
  }
  sort(V.begin(), V.end());
  map<char, char> res;
  for (auto i = 0; i < 3; i++)
  {
    res[get<1>(V[i])] = 'A' + i;
  }
  return res;
}

map<char, char> make_rev(map<char, char> const &M)
{
  map<char, char> res;
  for (auto x : M)
  {
    res[x.second] = x.first;
  }
  return res;
}

string convert(string const &S, map<char, char> const &M)
{
  stringstream SS{};
  for (auto x : S)
  {
    SS << M.at(x);
  }
  return SS.str();
}

vector<string> split(string const &S, char c)
{
  vector<string> res;
  stringstream SS{};
  for (auto x : S)
  {
    if (x == c)
    {
      res.push_back(SS.str());
      SS.clear();
    }
    else
    {
      SS << x;
    }
  }
  return res;
}

string make_ans(string const &S)
{
  vector<int> cnt = count(S);
  assert(cnt[0] <= cnt[1] && cnt[1] == cnt[2]);
  vector<string> V = split(S, 'A');
  vector<int> now(3, 0);
  vector<vector<bool>> used(V.size());
  for (auto i = 0u; i < V.size(); i++)
  {
    used[i] = vector<bool>(V[i].size(), false);
  }
  // 1st step
  for (auto i = 0u; i < V.size(); i++)
  {
    if (V[i].size() % 2 == 1)
    {
      used[i][0] = true;
      now[V[i][0] - 'A']++;
    }
  }
  assert(now[0] == 0 && now[1] == now[2]);
  // 2nd step
  for (auto i = 1u; i < V.size() - 1; i++)
  {
    if (V[i].size() % 2 == 0)
    {
      used[i][0] = used[i][1] = true;
      now[V[i][0] - 'A']++;
      now[V[i][1] - 'A']++;
    }
  }
  assert(now[0] == 0 && now[1] == now[2]);
  // 3rd step
  if (now[1] < cnt[0])
  {
    for (auto i = 0u; i < V.size(); i++)
    {
      int num = V[i].size() - 1;
      while (num >= 1 && !used[i][num] && !used[i][num - 1])
      {
        used[i][num] = used[i][num - 1] = true;
        now[V[i][num] - 'A']++;
        now[V[i][num - 1] - 'A']++;
        num -= 2;
        if (now[1] == cnt[0])
        {
          break;
        }
      }
      if (now[1] == cnt[0])
      {
        break;
      }
    }
  }
  assert(now[0] == 0 && now[1] == now[2] && cnt[0] == now[1]);
  // make ans
  stringstream SS{};
  for (auto i = 0u; i < V.size(); i++)
  {
    for (auto j = 0u; j < V[i].size(); j++)
    {
      if (used[i][j])
      {
        SS << V[i][j];
      }
    }
    if (i < V.size() - 1)
    {
      SS << 'A';
    }
  }
  return SS.str();
}

string erase_C(string const &S)
{
  vector<int> cnt = count(S);
  stringstream SS{};
  for (auto i = 0u; i < S.size(); i++)
  {
    if (cnt[2] > cnt[1])
    {
      if (S[i] == 'C')
      {
        if (i - 1 >= 0 && i + 1 < S.size())
        {
          if ((S[i - 1] == 'A' && S[i + 1] == 'B') || (S[i - 1] == 'B' && S[i + 1] == 'A'))
          {
            cnt[2]--;
            continue;
          }
        }
        else
        {
          cnt[2]--;
          continue;
        }
      }
    }
    SS << S[i];
  }
  return SS.str();
}

string erase_AC(string const &S)
{
  vector<int> cnt = count(S);
  assert(cnt[0] <= cnt[1] && cnt[1] < cnt[2]);
  stringstream res{};
  for (auto i = 0u; i < S.size(); i++)
  {
    if (cnt[1] < cnt[2] && i < S.size() - 1 && S[i] == 'A' && S[i + 1] == 'C')
    {
      ++i;
      cnt[0]--;
      cnt[2]--;
    }
    else
    {
      res << S[i];
    }
  }
  return res.str();
}

int main()
{
  string S;
  cin >> S;
  S = reduce(S);
  map<char, char> M, R;
  M = make_map(S);
  R = make_rev(M);
  S = convert(S, M);
#if DEBUG == 1
  cerr << "S = " << S << endl;
#endif
  vector<int> cnt = count(S);
  if (cnt[1] < cnt[2])
  {
    S = erase_C(S);
#if DEBUG == 1
    cerr << "S = " << S << endl;
#endif
    cnt = count(S);
    if (cnt[1] < cnt[2])
    {
      S = erase_AC(S);
#if DEBUG == 1
      cerr << "S = " << S << endl;
#endif
    }
  }
  string ans{make_ans(S)};
#if DEBUG == 1
  cerr << "ans = " << ans << endl;
#endif
  ans = convert(ans, R);
  cout << ans << endl;
}