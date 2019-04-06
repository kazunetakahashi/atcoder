#define DEBUG 1

/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 4/6/2019, 9:15:31 PM
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

ll X, Y, Z, W, K;
ll A[1010];
ll B[1010];
ll C[1010];
vector<ll> D;
vector<ll> ans;

void flush()
{
  assert((ll)ans.size() == K);
  for (auto x : ans)
  {
    cout << x << endl;
  }
}

int main()
{
  cin >> X >> Y >> Z >> K;
  for (auto i = 0; i < X; i++)
  {
    cin >> A[i];
  }
  for (auto i = 0; i < Y; i++)
  {
    cin >> B[i];
  }
  for (auto i = 0; i < Z; i++)
  {
    cin >> C[i];
  }
  W = Y * Z;
  for (auto i = 0; i < Y; i++)
  {
    for (auto j = 0; j < Z; j++)
    {
      D.push_back(B[i] + C[j]);
    }
  }
  sort(A, A + X);
  reverse(A, A + X);
  sort(D.begin(), D.end());
  reverse(D.begin(), D.end());
  ll ind[1010];
  fill(ind, ind + X, 0);
  for (auto i = 0; i < K; i++)
  {
    ll maxi = 0;
    ll index = 0;
    for (auto j = 0; j < X; j++)
    {
      if (ind[j] >= W)
      {
        continue;
      }
      ll t = D[ind[j]] + A[j];
      if (t > maxi)
      {
        maxi = t;
        index = j;
      }
    }
    ans.push_back(maxi);
    ind[index]++;
  }
  flush();
}