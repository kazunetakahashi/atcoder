#define DEBUG 1

/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 5/4/2019, 9:10:38 PM
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

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

// const int C = 1e6+10;
// const ll M = 1000000007;

ll H, W;
ll N;
string S, T;
ll sr, sc;
int A[200010];
int B[200010];
typedef tuple<int, int> event;

bool solve(int X, int s, vector<event> V)
{
  int maxi = s, mini = s;
  for (auto x : V)
  {
    int player = get<0>(x);
    int move = get<1>(x);
    if (player == 0 && move == 0)
    {
      mini--;
    }
    else if (player == 0 && move == 1)
    {
      maxi++;
    }
    else if (player == 1 && move == 0)
    {
      if (maxi > mini)
      {
        maxi--;
      }
    }
    else
    {
      if (maxi > mini)
      {
        mini++;
      }
    }
    if (mini < 0 || maxi >= X)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  cin >> H >> W >> N >> sr >> sc >> S >> T;
  sr--;
  sc--;
  for (auto i = 0; i < N; i++)
  {
    if (S[i] == 'L')
    {
      A[i] = 0;
    }
    else if (S[i] == 'R')
    {
      A[i] = 1;
    }
    else if (S[i] == 'U')
    {
      A[i] = 2;
    }
    else
    {
      assert(S[i] == 'D');
      {
        A[i] = 3;
      }
    }
  }
  for (auto i = 0; i < N; i++)
  {
    if (T[i] == 'L')
    {
      B[i] = 0;
    }
    else if (T[i] == 'R')
    {
      B[i] = 1;
    }
    else if (T[i] == 'U')
    {
      B[i] = 2;
    }
    else
    {
      assert(T[i] == 'D');
      {
        B[i] = 3;
      }
    }
    vector<event> V;
    for (auto i = 0; i < N; i++)
    {
      if (A[i] < 2)
      {
        V.push_back(event(0, A[i]));
      }
      if (B[i] < 2)
      {
        V.push_back(event(1, B[i]));
      }
    }
    vector<event> U;
    for (auto i = 0; i < N; i++)
    {
      if (A[i] >= 2)
      {
        U.push_back(event(0, A[i] - 2));
      }
      if (B[i] >= 2)
      {
        U.push_back(event(1, B[i] - 2));
      }
    }
    if (solve(H, sr, V) || solve(W, sc, U))
    {
      cout << "NO" << endl;
    }
    else
    {
      cout << "YES" << endl;
    }
  }
}