#define DEBUG 1

/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-3-24 21:05:52
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

int N, Q;
string S;
int l[100010];
int r[100010];
int imos[2][100010];

int main()
{
  cin >> N >> Q >> S;
  for (auto i = 0; i < Q; i++)
  {
    cin >> l[i] >> r[i];
    l[i]--;
  }
  fill(&imos[0][0], &imos[0][0] + 100010, 0);
  for (auto i = 0; i < N - 1; i++)
  {
    if (S[i] == 'A' && S[i + 1] == 'C')
    {
      imos[0][i + 1]++;
      imos[1][i + 2]++;
    }
  }
  for (auto i = 1; i <= N; i++)
  {
    imos[0][i] += imos[0][i - 1];
    imos[1][i] += imos[1][i - 1];
  }
  for (auto i = 0; i < Q; i++)
  {
    if (imos[1][r[i]] == imos[0][r[i]])
    {
      cout << imos[1][r[i]] - imos[1][l[i] + 1] << endl;
    }
    else
    {
      cout << imos[1][r[i]] - imos[1][l[i] + 1] << endl;
    }
  }
}