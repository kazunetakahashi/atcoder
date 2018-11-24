/**
 * File    : C.cpp
 * Author  : Kazune Takahashi
 * Created : 11/24/2018, 8:48:33 PM
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

int N;
string S;
int Q;
int k[100];
typedef tuple<int, ll> X;
vector<X> D, C;

int main()
{
  cin >> N >> S >> Q;
  for (auto i = 0; i < Q; i++)
  {
    cin >> k[i];
  }
  int m = 0;
  for (auto i = 0; i < N; i++)
  {
    if (S[i] == 'D')
    {
      D.push_back(X(i, m));
    }
    else if (S[i] == 'M')
    {
      m++;
    }
    else if (S[i] == 'C')
    {
      C.push_back(X(i, m));
    }
  }
  int D_size = D.size();
  int C_size = C.size();
  for (auto q = 0; q < Q; q++)
  {
    int K = k[q];
    ll ans = 0;
    ll ind_d = 0;
    ll left = 0;
    ll right = 0;
    ll sum = 0;
    while (ind_d < D_size)
    {
      while (left < C_size && get<0>(C[left]) < get<0>(D[ind_d]))
      {
        sum -= get<1>(C[left]);
        left++;
      }
      while (right < C_size && get<0>(C[right]) - get<0>(D[ind_d]) < K)
      {
        sum += get<1>(C[right]);
        right++;
      }
      ans += sum - (right - left) * get<1>(D[ind_d]);
      ind_d++;
    }
    cout << ans << endl;
  }
}