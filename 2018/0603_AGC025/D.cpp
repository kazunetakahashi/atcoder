/**
 * File    : D.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-6-3 21:25:19
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

typedef complex<int> P;

int N;
int D[2];
vector<P> ans;
vector<P> F;

void flush()
{
  for (auto p : ans)
  {
    int x = p.real();
    int y = p.imag();
    cout << x << " " << y << endl;
  }
}

void make_forbid(int X)
{
  for (int i = 0; i <= 2 * N; i++)
  {
    int j = round(sqrt(X - i * i));
    if (i * i + j * j == X)
    {
      F.push_back(P(i, j));
      F.push_back(P(-i, j));
      F.push_back(P(i, -j));
      F.push_back(P(-i, -j));
      F.push_back(P(j, i));
      F.push_back(P(j, -i));
      F.push_back(P(-j, i));
      F.push_back(P(-j, -i));
    }
  }
}

bool valid(P p)
{
  int x = p.real();
  int y = p.imag();
  return (0 <= x && x < 2 * N) && (0 <= y && y < 2 * N);
}

bool B[1010][1010];
vector<P> pts;
random_device seed;
mt19937 engine(seed());

int main()
{
  cin >> N >> D[0] >> D[1];
  make_forbid(D[0]);
  make_forbid(D[1]);
  fill(&B[0][0], &B[0][0] + 1010 * 1010, true);
  for (auto i = 0; i < 2 * N; i++)
  {
    for (auto j = 0; j < 2 * N; j++)
    {
      if (B[i][j])
      {
        P p(i, j);
        ans.push_back(p);
        if (ans.size() == N * N)
        {
          flush();
          return 0;
        }
        for (auto q : F)
        {
          P r = p + q;
          if (valid(r))
          {
            B[r.real()][r.imag()] = false;
          }
        }
      }
    }
  }
  while (true)
  {
    fill(&B[0][0], &B[0][0] + 1010 * 1010, true);
    ans.clear();
    pts.clear();
    for (auto i = 0; i < 2 * N; i++)
    {
      for (auto j = 0; j < 2 * N; j++)
      {
        pts.push_back(P(i, j));
      }
    }
    shuffle(pts.begin(), pts.end(), engine);
    for (auto p : pts)
    {
      int i = p.real();
      int j = p.imag();
      if (B[i][j])
      {
        ans.push_back(p);
        if (ans.size() == N * N)
        {
          flush();
          return 0;
        }
        for (auto q : F)
        {
          P r = p + q;
          if (valid(r))
          {
            B[r.real()][r.imag()] = false;
          }
        }
      }
    }
  }
}