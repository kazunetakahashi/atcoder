/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-7 14:05:18
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
#include <chrono>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

typedef tuple<int, int, int, int, int> state; // x, y, dir, a, b

int A, B;
int h, w;
string c[100];

stack<state> S;

bool valid(int x, int y, int a, int b)
{
  return (a <= A && b <= B && c[x][y] == '.');
}

int main()
{
  auto start = std::chrono::system_clock::now();
  cin >> A >> B;
  cin >> h >> w;
  for (auto i = 0; i < h; i++)
  {
    cin >> c[i];
  }
  S.push(state(1, 1, 0, 0, 0));
  while (!S.empty())
  {
    auto end = std::chrono::system_clock::now();
    double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
    if (elapsed > 2000) {
      cout << "Yes" << endl;
      return 0;
    }
    int now_x = get<0>(S.top());
    int now_y = get<1>(S.top());
    int now_dir = get<2>(S.top());
    int now_a = get<3>(S.top());
    int now_b = get<4>(S.top());
    #if DEBUG == 1
    cerr << "(" << now_x << ", " << now_y << "), "
         << now_dir << ", "
         << "(" << now_a << ", " << now_b << ")" << endl;
    #endif
    S.pop();
    if (now_x == h - 2 && now_y == w - 2 && now_a == A && now_b == B)
    {
      cout << "Yes" << endl;
      return 0;
    }
    else
    {
      int new_dir[3] = {(now_dir + 1) % 4, (now_dir + 3) % 4, now_dir};
      int new_a[3] = {now_a + 1, now_a, now_a};
      int new_b[3] = {now_b, now_b + 1, now_b};
      for (auto k = 0; k < 3; k++)
      {
        int new_x = now_x + dx[new_dir[k]];
        int new_y = now_y + dy[new_dir[k]];
        if (valid(new_x, new_y, new_a[k], new_b[k]))
        {
          S.push(state(new_x, new_y, new_dir[k], new_a[k], new_b[k]));
        }
      }
    }
  }
  cout << "No" << endl;
}