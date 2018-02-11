/**
 * File    : B.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-11 19:57:26
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
#include <chrono>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.

typedef long long ll;

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

struct point
{
  int x, y;
};

typedef tuple<point, point> sw;

int dist(point p, point q)
{
  return abs(p.x - q.x) + abs(p.y - q.y);
}

void flush(vector<sw> ans)
{
  for (auto e : ans)
  {
    point k = get<0>(e);
    point l = get<1>(e);
    cout << k.x << " " << k.y << " " << l.x << " " << l.y << endl;
  }
}

int H, W, D, K;
vector<point> V;
int field[200][200];

sw make_swap(point k, point l)
{
  int numk = field[k.x][k.y];
  int numl = field[l.x][l.y];
  if (numk >= 0 && numl >= 0)
  {
    swap(V[numk], V[numl]);
  }
  else if (numk >= 0)
  {
    V[numk] = l;
  }
  else if (numl >= 0)
  {
    V[numl] = k;
  }
  field[k.x][k.y] = numl;
  field[l.x][l.y] = numk;
  return make_tuple(k, l);
}

int main()
{
  //auto start_time = std::chrono::system_clock::now();
  cin >> H >> W >> D >> K;
  fill(&field[0][0], &field[0][0] + 200 * 200, -1);
  for (auto i = 0; i < D; i++)
  {
    int x, y;
    cin >> x >> y;
    V.push_back((point){x, y});
    field[x][y] = i;
  }
  vector<sw> ans;
  ans.push_back(make_swap(point{0, 0}, V[0]));
  ans.push_back(make_swap(point{H - 1, W - 1}, V[D - 1]));
  //auto end_time = std::chrono::system_clock::now();
  //double timer = std::chrono::duration_cast<std::chrono::milliseconds>(
  //                   end_time - start_time)
  //                   .count();
  vector<int> tonari;
  for (auto i = 0; i < D - 2; i++)
  {
    tonari.push_back(dist(V[i], V[i + 2]));
  }
  vector<tuple<int, int>> seiri;
  for (auto i = 0; i < D - 2; i++)
  {
    seiri.push_back(make_tuple(tonari[i], i));
  }
  sort(seiri.begin(), seiri.end());
  vector<bool> used(D, false);
  int cnt = 0;
  for (auto e : seiri)
  {
    int n = get<1>(e) + 1;
    int tonari1 = n - 1;
    int tonari2 = n + 1;
    if (tonari1 >= 0 && !used[tonari1] && tonari2 < D && !used[tonari2])
    {
      used[n] = true;
      // cerr << "n = " << n << " is used." << endl;
      cnt++;
    }
    if (cnt >= K - 2)
      break;
  }
  for (auto i = 0; i < D; i++)
  {
    if (used[i])
    {
      point p = V[i - 1];
      point q = V[i + 1];
      int lx = max(0, min(p.x, q.x) - 10);
      int ux = min(H - 1, max(p.x, q.x) + 10);
      int ly = max(0, min(p.y, q.y) - 10);
      int uy = min(W - 1, max(p.y, q.y) + 10);
      int mini = 10000000;
      point minp = V[i];
      for (auto j = lx; j < ux; j++)
      {
        for (auto k = ly; k < uy; k++)
        {
          point now = (point){j, k};
          int d = dist(p, now) + dist(now, q);
          if (mini > d)
          {
            mini = d;
            minp = now;
          }
        }
      }
      ans.push_back(make_swap(V[i], minp));
    }
  }
  flush(ans);
}