/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-14 19:57:06
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

vector<int> V;
int N;
vector<int> W;

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    int x;
    cin >> x;
    V.push_back(x);
  }
  W = V;
  sort(W.begin(), W.end());
  int A = W[N / 2 - 1];
  int B = W[N / 2];
  for (auto i = 0; i < N; i++)
  {
    if (V[i] <= A) {
      cout << B << endl;
    } else {
      cout << A << endl;
    }
  }
}