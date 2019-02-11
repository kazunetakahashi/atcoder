#define DEBUG 1

/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2/11/2019, 7:07:57 PM
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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

int N, M;
int A[50][50];

void WA()
{
  cout << "1000 1000 1000" << endl;
}

void RE()
{
  assert(false);
}

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      cin >> A[i][j];
    }
  }
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (A[i][j] == 1)
      {
        bool ok = true;
        int ary[10];
        fill(ary, ary + 10, 0);
        for (auto k = 0; k < 4; k++)
        {
          int x = i + dx[k];
          int y = j + dy[k];
          if (0 <= i && i < N && 0 <= j && j < N && A[x][y] == 1)
          {
            ok = false;
            break;
          }
          else
          {
            ary[A[x][y]]++;
          }
        }
        if (ok)
        {
          for (auto k = 0; k < 10; k++)
          {
            if (ary[k] == 4)
            {
              RE();
            }
          }
        }
      }
    }
  }
  WA();
}