/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 11/20/2018, 11:10:45 PM
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

int main()
{
  string A, B;
  cin >> A >> B;
  if (A == B)
  {
    cout << "EQUAL" << endl;
    return 0;
  }
  if (A.size() > B.size())
  {
    cout << "GREATER" << endl;
  }
  else if (A.size() < B.size())
  {
    cout << "LESS" << endl;
  }
  else
  {
    for (auto i = 0; i < (int)A.size(); i++)
    {
      if (A[i] > B[i])
      {
        cout << "GREATER" << endl;
        return 0;
      }
      else if (A[i] < B[i])
      {
        cout << "LESS" << endl;
        return 0;
      }
    }
  }
  return 1;
}