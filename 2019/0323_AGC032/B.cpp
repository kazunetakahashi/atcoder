#define DEBUG 1

/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 3/23/2019, 10:22:47 PM
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

int N;
vector<vector<int>> V;
typedef tuple<int, int> edge;
vector<edge> E;

void flush()
{
  int S = V.size();
  for (auto i = 0; i < S; i++)
  {
    for (auto j = i + 1; j < S; j++)
    {
      for (auto x : V[i])
      {
        for (auto y : V[j])
        {
          E.push_back(edge(x, y));
        }
      }
    }
  }
  for (auto x : E)
  {
    cout << get<0>(x) << " " << get<1>(x) << endl;
  }
}

int main()
{
  cin >> N;
  if (N % 2 == 0)
  {
    for (auto i = 1; i <= N / 2; i++)
    {
      V.push_back({i, N + 1 - i});
    }
  }
  else
  {
    V.push_back({N});
    N--;
    for (auto i = 1; i <= N / 2; i++)
    {
      V.push_back({i, N + 1 - i});
    }
  }
  flush();
}