/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-4-7 15:21:39
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

int N;
int A[100010];
bool visited[100010];

int main()
{
  cin >> N;
  for (auto i = 0; i < N; i++)
  {
    cin >> A[i];
    A[i]--;
  }
  fill(visited, visited + 100010, false);
  for (auto i = 0; i < N; i++)
  {
    if (!visited[i])
    {
      int now = i;
      int cnt = 0;
      while (!visited[now])
      {
        ++cnt;
        visited[now] = true;
        now = A[now];
      }
      if (cnt%2 != 0)
      {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  cout << N / 2 << endl;
}