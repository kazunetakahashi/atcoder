#define DEBUG 1

/**
 * File    : B2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-21 22:10:05
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

int H, W, N;
int sr, sc;
string S, T;

int main()
{
  cin >> H >> W >> N >> sr >> sc >> S >> T;
  int left = 0;
  int right = W - 1;
  int up = 0;
  int down = H - 1;
  sr--;
  sc--;
  reverse(T.begin(), T.end());
  reverse(S.begin(), S.end());
  for (auto i = 0; i < N; i++)
  {
    if (T[i] == 'L' && right < W - 1)
    {
      right++;
    }
    else if (T[i] == 'R' && left > 0)
    {
      left--;
    }
    else if (T[i] == 'U' && down < H - 1)
    {
      down++;
    }
    else if (T[i] == 'D' && up > 0)
    {
      up--;
    }
    if (S[i] == 'L')
    {
      left++;
    }
    else if (S[i] == 'R')
    {
      right--;
    }
    else if (S[i] == 'U')
    {
      up++;
    }
    else if (S[i] == 'D')
    {
      down--;
    }
    if (right < left || down < up)
    {
      cout << "NO" << endl;
      return 0;
    }
  }
  if (left <= sc && sc <= right && up <= sr && sr <= down)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}