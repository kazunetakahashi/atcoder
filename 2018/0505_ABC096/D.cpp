/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-5 21:10:07
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

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

const int MAX_SIZE = 1000010; // 10000010でもよさそう？
bool isprime[MAX_SIZE];
vector<ll> prime_num;

void init()
{
  fill(isprime, isprime + MAX_SIZE, true);
  isprime[0] = isprime[1] = false;
  for (auto i = 2; i < MAX_SIZE; i++)
  {
    if (isprime[i])
    {
      prime_num.push_back(i);
      for (auto j = 2; i * j < MAX_SIZE; j++)
      {
        isprime[i * j] = false;
      }
    }
  }
}

bool prime(long long x)
{ // 2 \leq x \leq MAX_SIZE^2
  if (x < MAX_SIZE)
  {
    return isprime[x];
  }
  for (auto e : prime_num)
  {
    if (x % e == 0)
      return false;
  }
  return true;
}

int main()
{
  init();
  int N;
  cin >> N;
  vector<ll> A;
  for (auto x : prime_num)
  {
    assert(x <= 55555);
    if (x % 5 == 1)
    {
      A.push_back(x);
      if ((int)A.size() == N)
      {
        break;
      }
    }
  }
  for (auto i = 0; i < N; i++)
  {
    cout << A[i];
    if (i < N-1)
    {
      cout << " ";
    }
    else
    {
      cout << endl;
    }
  }
}
