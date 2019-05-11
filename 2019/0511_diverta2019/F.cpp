#define DEBUG 1

/**
 * File    : F.cpp
 * Author  : Kazune Takahashi
 * Created : 2019-5-11 22:04:36
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

typedef tuple<int, int> edge;
typedef tuple<int, int, int> info;

int N, M;
int a[210];
int b[210];
vector<edge> V[20];
vector<int> W[1 << 20];
vector<int> masks;

int main()
{
  cin >> N >> M;
  for (auto i = 0; i < M; i++)
  {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }
  for (auto i = 0; i < N - 1; i++)
  {
    V[a[i]].push_back(edge(b[i], i));
    V[b[i]].push_back(edge(a[i], i));
  }
  for (auto i = N - 1; i < M; i++)
  {
    edge from[20];
    fill(from, from + 20, edge(-1, -1));
    stack<info> S;
    S.push(info(a[i], -1, -1));
    while (!S.empty())
    {
      info e = S.top();
      int dst = get<0>(e);
      int src = get<1>(e);
      int num = get<2>(e);
      S.pop();
      if (from[dst] == edge(-1, -1))
      {
        from[dst] = edge(src, num);
        if (dst == b[i])
        {
          break;
        }
        for (auto x : V[dst])
        {
          int next = get<0>(x);
          int next_num = get<1>(x);
          if (from[next] == edge(-1, -1))
          {
            S.push(info(next, dst, next_num));
          }
        }
      }
    }
    int mask = 0;
    int temp = b[i];
    while (temp != a[i])
    {
      int num = get<1>(from[temp]);
      mask += (1 << num);
      temp = get<0>(from[temp]);
    }
    masks.push_back(mask);
#if DEBUG == 1
    cerr << "i = " << i << ", mask = " << mask << endl;
#endif
  }
}