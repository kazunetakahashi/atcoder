#define DEBUG 1

/**
 * File    : C2.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-28 11:49:49
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

int main()
{
  cin >> N >> Q >> S;
  for (auto i = 0; i < Q; i++)
  {
    cin >> l[i] >> r[i];
  }
  vector<int> sum(N + 1, 0);
  for (auto i = 1; i < N; i++)
  {
    if (S[i - 1] == 'A' && S[i] == 'C')
    {
      sum[i + 1] = sum[i] + 1;
    }
    else
    {
      sum[i + 1] = sum[i];
    }
  }
  for (auto i = 0; i < Q; i++)
  {
    cout << sum[r[i]] - sum[l[i] - 1] << endl;
  }
}