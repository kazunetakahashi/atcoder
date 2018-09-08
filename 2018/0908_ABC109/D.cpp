/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-9-8 21:12:40
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
#include <random> // auto rd = bind(uniform_int_distribution<int>(0, 9), mt19937(19920725));
#include <chrono> // std::chrono::system_clock::time_point start_time, end_time;
// start = std::chrono::system_clock::now();
// double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end_time-start_time).count();
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

int H, W;
bool a[510][510];

typedef tuple<int, int, int, int> X;
vector<X> V;
int odd[510];

void flush()
{
  int N = (int)V.size();
  cout << N << endl;
  for (auto i = 0; i < N; i++)
  {
    X x = V[i];
    cout << get<0>(x) + 1 << " " << get<1>(x) + 1 << " " << get<2>(x) + 1 << " " << get<3>(x) + 1 << endl;
  }
}

void make_swap(int x, int y, int z, int w)
{
  swap(a[x][y], a[z][w]);
  V.push_back(X(x, y, z, w));
}

int main()
{
  cin >> H >> W;
  for (auto i = 0; i < H; i++)
  {
    for (auto j = 0; j < W; j++)
    {
      int x;
      cin >> x;
      a[i][j] = (x % 2 == 1);
    }
  }
  fill(odd, odd + 510, -1);
  for (auto i = 0; i < H; i++)
  {
    int y = -1;
    int cnt = 0;
    for (auto j = 0; j < W; j++)
    {
      if (a[i][j])
      {
        cerr << "(" << i << ", " << j << ")" << endl;
        if (cnt % 2 == 0)
        {
          y = j;
        }
        else
        {
          int z = j;
          for (auto k = y; k < z - 1; k++)
          {
            make_swap(i, k, i, k + 1);
          }
        }
        cnt++;
      }
    }
    if (cnt % 2 == 1)
    {
      odd[i] = y;
      for (auto k = y; k < W - 1; k++)
      {
        make_swap(i, k, i, k + 1);
      }
    }
  }
  int x;
  int cnt = 0;
  for (auto i = 0; i < H; i++)
  {
    if (odd[i] >= 0)
    {
      if (cnt % 2 == 0)
      {
        x = i;
      }
      else
      {
        int z = i;
        for (auto k = x; k < z - 1; k++)
        {
          make_swap(k, W - 1, k + 1, W - 1);
        }
      }
      cnt++;
    }
  }
  flush();
}