/**
 * File    : E.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-3-11 21:22:55
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

// const ll dx[4] = {1, 0, -1, 0};
// const ll dy[4] = {0, 1, 0, -1};

// const ll C = 1e6+10;
// const ll M = 1000000007;

ll N, A, B;

bool ok()
{
  return (1 <= A && A <= N && 1 <= B && B <= N && A * B >= N);
}

vector<ll> V;
vector<ll> W;
map <ll, ll> M;

int main()
{
  cin >> N >> A >> B;
  if (!ok())
  {
    cout << -1 << endl;
    return 0;
  }
  ll now = 0;
  for (auto j = 0; j < A; j++)
    {
            if ((ll)V.size() >= N)
        break;

      V.push_back(now);
      now++;
  }
  now -= N * N;
  for (auto i = 0; i < B; i++)
  {
      if ((ll)V.size() >= N)
        break;
    V.push_back(now);
    now -= 4 * A;
  }
  now = -4 * A;
  for (auto i = 0; i < B; i++)
  {
    for (auto j = 0; j < A; j++)
    {
      if ((ll)V.size() >= N)
        break;
      V.push_back(now);
      now++;
    }
    if ((ll)V.size() >= N)
      break;
    now -= 4 * A;
  }
  W = V;
  sort(W.begin(), W.end());
  for (auto i = 0; i < N; i++)
  {
    M[W[i]] = i+1;
  }
  for (auto i = 0; i < N; i++)
  {
    V[i] = M[V[i]];
  }
  for (auto i = 0; i < N; i++)
  {
    cout << V[i];
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