#define DEBUG 1

/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 2/23/2019, 11:25:10 PM
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

int N, K;
int a[60];

bool able = true;
vector<int> V;

void flush()
{
  if (!able)
  {
    cout << -1 << endl;
  }
  else
  {
    int S = V.size();
    cout << S << endl;
    for (auto i = 0; i < S; i++)
    {
      cout << V[i] + 1;
      if (i < S - 1)
      {
        cout << " ";
      }
    }
  }
  exit(0);
}

typedef tuple<int, int> C;
vector<C> W;

int main()
{
  cin >> N >> K;
  for (auto i = 0; i < N; i++)
  {
    cin >> a[i];
    W.push_back(C(a[i], i));
  }
  sort(W.begin(), W.end());
  reverse(W.begin(), W.end());
  for (auto i = 0; i < 100; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (get<0>(W[j]) == 0)
      {
        able = false;
        flush();
      }
      V.push_back(get<1>(W[j]));
      get<0>(W[j])--;
      if (i > 0 && j >= N - 2)
      {
        K--;
      }
      else if (i == 0 && j == N - 1)
      {
        K--;
      }
      if (K < 0)
      {
        flush();
      }
    }
  }
}