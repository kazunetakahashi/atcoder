#define DEBUG 1

/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 5/19/2019, 9:28:18 PM
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

ll M, K;

int main()
{
  cin >> M >> K;
  if (!(0 <= K && K < (1 << M)))
  {
    cout << "-1" << endl;
    return 0;
  }
  if (M == 0)
  {
    cout << "0 0" << endl;
  }
  else if (M == 1)
  {
    if (K == 0)
    {
      cout << "0 0 1 1" << endl;
    }
    else
    {
      cout << "-1" << endl;
    }
  }
  else
  {
    vector<int> V;
    vector<int> W;
    for (auto i = 0; i < (1 << M); i++)
    {
      if (i == K)
      {
        continue;
      }
      V.push_back(i);
      W.push_back(i);
    }
    reverse(W.begin(), W.end());
    for (auto x : V)
    {
      cout << x << " ";
    }
    cout << K;
    for (auto x : W)
    {
      cout << x << " ";
    }
    cout << K << endl;
  }
}