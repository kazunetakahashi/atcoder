/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-5-5 21:02:18
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
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

ll A[3];
int K;

int main()
{
  cin >> A[0] >> A[1] >> A[2];
  cin >> K;
  sort(A, A + 3);
  for (auto i = 0; i < K; i++)
  {
    A[2] *= 2;
  }
  cout << A[0] + A[1] + A[2] << endl;
}