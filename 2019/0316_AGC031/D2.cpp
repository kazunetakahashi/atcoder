#define DEBUG 1

/**
 * File    : D2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-29 20:27:35
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
#include <functional>
#include <random>
#include <chrono>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

/*
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
*/

/*
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
*/

// const ll MOD = 1000000007;

int N, K;
vector<int> a, b, A, B, x, y, I;

vector<int> inv(vector<int> V)
{
  vector<int> W(N);
  for (auto i = 0; i < N; i++)
  {
    W[V[i]] = i;
  }
  return W;
}

vector<int> mult(vector<int> V, vector<int> W)
{
  vector<int> U(N);
  for (auto i = 0; i < N; i++)
  {
    U[i] = V[W[i]];
  }
  return U;
}

vector<int> power(vector<int> V, int n)
{
  if (n == 0)
  {
    return I;
  }
  else if (n % 2 == 0)
  {
    vector<int> W = power(V, n / 2);
    return mult(W, W);
  }
  else
  {
    return mult(V, power(V, n - 1));
  }
}

vector<int> f(vector<int> V, vector<int> W)
{
  return mult(W, inv(V));
}

void flush(vector<int> V)
{
  for (auto i = 0; i < N; i++)
  {
    cout << V[i] + 1;
    if (i < N - 1)
    {
      cout << " ";
    }
    else
    {
      cout << endl;
    }
  }
}

int main()
{
  cin >> N >> K;
  K--;
  a = vector<int>(N);
  b = vector<int>(N);
  I = vector<int>(N);
  for (auto i = 0; i < N; i++)
  {
    I[i] = i;
  }
  for (auto i = 0; i < N; i++)
  {
    cin >> a[i];
    a[i]--;
  }
  for (auto i = 0; i < N; i++)
  {
    cin >> b[i];
    b[i]--;
  }
  A = inv(a);
  B = inv(b);
  // $x = bABa$, $y = AbaB$
  x = mult(mult(b, A), mult(B, a));
  y = mult(mult(A, b), mult(a, B));
  if (K == 0)
  {
    flush(a);
    return 0;
  }
  int n = (K - 1) / 6;
  vector<int> p = mult(mult(power(x, n), b), power(y, n));
  vector<int> q = mult(mult(power(x, n), mult(b, A)), power(y, n));
  for (auto i = 6 * n + 1; i < K; i++)
  {
    vector<int> r = f(p, q);
    p = q;
    q = r;
  }
  flush(p);
}