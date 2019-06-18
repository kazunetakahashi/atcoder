#define DEBUG 1
/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 6/18/2019, 2:02:05 PM
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
typedef long long ll;
void Yes()
{
  cout << "YES" << endl;
  exit(0);
}
void No()
{
  cout << "NO" << endl;
  exit(0);
}
const int MAX_SIZE = 1000010;
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
  mint &operator/=(const mint &a) { return (*this *= power(MOD - 2)); }
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
mint inv[MAX_SIZE];
mint fact[MAX_SIZE];
mint factinv[MAX_SIZE];
void init()
{
  inv[1] = 1;
  for (int i = 2; i < MAX_SIZE; i++)
  {
    inv[i] = (-inv[mint::MOD % i]) * (mint::MOD / i);
  }
  fact[0] = factinv[0] = 1;
  for (int i = 1; i < MAX_SIZE; i++)
  {
    fact[i] = mint(i) * fact[i - 1];
    factinv[i] = inv[i] * factinv[i - 1];
  }
}
mint choose(int n, int k)
{
  if (n >= 0 && k >= 0 && n - k >= 0)
  {
    return fact[n] * factinv[k] * factinv[n - k];
  }
  return 0;
}
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
// const double epsilon = 1e-10;
// const ll infty = 1000000000000000LL;
const int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

typedef vector<string> ban;
const int C = 19;

enum class state
{
  black_win,
  white_win,
  black_even,
  white_even,
  error,
};

class Go
{
public:
  ban B;
  vector<int> cnt = vector<int>(2, 0);
  Go() {}
  Go(ban V) : B(V)
  {
    for (auto i = 0; i < C; i++)
    {
      for (auto j = 0; j < C; j++)
      {
        if (B[i][j] == 'o')
        {
          cnt[0]++;
        }
        else if (B[i][j] == 'x')
        {
          cnt[1]++;
        }
      }
    }
  }

  bool win(char c)
  {
    for (auto i = 0; i < C; i++)
    {
      for (auto j = 0; j < C; j++)
      {
        for (auto a = 0; a < 8; a++)
        {
          bool ok = true;
          for (auto k = 0; k < 5; k++)
          {
            int x = i + dx[a] * k;
            int y = j + dy[a] * k;
            if (0 <= x && x < C && 0 <= y && y < C && B[x][y] != c)
            {
              ok = false;
              break;
            }
          }
          if (ok)
          {
            return true;
          }
        }
      }
    }
    return false;
  }

  state st()
  {
    int t = cnt[0] - cnt[1];
    if (!(t == 0 || t == 1))
    {
      return state::error;
    }
    bool black_turn = (t == 1);
    bool black_win = win('o');
    bool white_win = win('x');
    if (black_win && white_win)
    {
      return state::error;
    }
    else if (black_win)
    {
      if (black_turn)
      {
        return state::black_win;
      }
      else
      {
        return state::error;
      }
    }
    else if (white_win)
    {
      if (!black_turn)
      {
        return state::white_win;
      }
      else
      {
        return state::error;
      }
    }
    else
    {
      if (black_turn)
      {
        return state::black_even;
      }
      else
      {
        return state::white_even;
      }
    }
  }
};

int main()
{
  // init();
  ban B;
  for (auto i = 0; i < C; i++)
  {
    string S;
    cin >> S;
    B.push_back(S);
  }
  Go I(B);
  state I_state = I.st();
#if DEBUG == 1
  cerr << I.cnt[0] << " VS " << I.cnt[1] << endl;
  cerr << "I_state: " << (int)I_state << endl;
#endif
  if (I_state == state::error)
  {
    No();
  }
  if (I_state == state::white_even || I_state == state::black_even)
  {
    Yes();
  }
  if (I_state == state::black_win)
  {
    for (auto i = 0; i < C; i++)
    {
      for (auto j = 0; j < C; j++)
      {
        Go before(B);
        if (before.B[i][j] == 'o')
        {
          before.B[i][j] = '.';
          before.cnt[0]--;
          if (before.st() == state::white_even)
          {
#if DEBUG == 1
            cerr << "Prev Board: " << endl;
            cerr << before.cnt[0] << " VS " << before.cnt[1] << endl;
            for (auto i = 0; i < C; i++)
            {
              cerr << before.B[i] << endl;
            }
#endif
            Yes();
          }
        }
      }
    }
    No();
  }
  if (I_state == state::white_win)
  {
    for (auto i = 0; i < C; i++)
    {
      for (auto j = 0; j < C; j++)
      {
        Go before(B);
        if (before.B[i][j] == 'x')
        {
          before.B[i][j] = '.';
          before.cnt[1]--;
          if (before.st() == state::black_even)
          {
            Yes();
#if DEBUG == 1
            cerr << "Prev Board: " << endl;
            for (auto i = 0; i < C; i++)
            {
              cerr << before.B[i] << endl;
            }
#endif
          }
        }
      }
    }
    No();
  }
}