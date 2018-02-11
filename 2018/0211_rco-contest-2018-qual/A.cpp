/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 2018-2-11 18:58:37
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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const char ch[4] = {'D', 'R', 'U', 'L'};

// const int C = 1e6+10;
// const ll M = 1000000007;

typedef tuple<int, int> place;
typedef tuple<int, int> score_map;
typedef tuple<int, vector<int>, vector<int>> state; // score, move, maps

int N, K, H, W, T;
string M[100][50];
place start[100];

int score(int m, vector<int> V)
{
  int x = get<0>(start[m]);
  int y = get<1>(start[m]);
  string map[50];
  for (auto i = 0; i < H; i++)
  {
    map[i] = M[m][i];
  }
  assert(map[x][y] == '@');
  map[x][y] = '.';
  int ans = 0;
  for (auto e : V)
  {
    int nx = x + dx[e];
    int ny = y + dy[e];
    if (map[nx][ny] == 'o')
    {
      ans++;
      map[nx][ny] = '.';
      x = nx;
      y = ny;
    }
    else if (map[nx][ny] == '.')
    {
      x = nx;
      y = ny;
    }
    else if (map[nx][ny] == 'x')
    {
      return ans;
    }
    else
    {
      assert(map[nx][ny] == '#');
    }
  }
  return ans;
}

state make_state(vector<int> moves)
{
  vector<score_map> V;
  for (auto i = 0; i < N; i++)
  {
    V.push_back(make_tuple(score(i, moves), i));
  }
  sort(V.begin(), V.end());
  reverse(V.begin(), V.end());
  int sum = 0;
  vector<int> maps;
  for (auto i = 0; i < K; i++)
  {
    sum += get<0>(V[i]);
    maps.push_back(get<1>(V[i]));
  }
  return make_tuple(sum, moves, maps);
}

void flush(vector<int> moves, vector<int> maps)
{
  assert((int)maps.size() == K);
  assert((int)moves.size() == T);
  for (auto i = 0; i < K; i++)
  {
    cout << maps[i];
    if (i < K - 1)
    {
      cout << " ";
    }
    else
    {
      cout << endl;
    }
  }
  for (auto x : moves)
  {
    cout << ch[x];
  }
  cout << endl;
}

int main()
{
  auto start_time = std::chrono::system_clock::now();
  cin >> N >> K >> H >> W >> T;
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < H; j++)
    {
      cin >> M[i][j];
    }
    bool ok = false;
    for (auto j = 0; j < H; j++)
    {
      for (auto k = 0; k < W; k++)
      {
        if (M[i][j][k] == '@')
        {
          start[i] = make_tuple(j, k);
          ok = true;
          break;
        }
        if (ok)
          break;
      }
    }
  }
  random_device rd;
  vector<state> S;
  mt19937 mt(rd());
  auto end_time = std::chrono::system_clock::now();
  while (true)
  {
    end_time = std::chrono::system_clock::now();
    double timer = std::chrono::duration_cast<std::chrono::milliseconds>(
                       end_time - start_time)
                       .count();
    if (timer > 3900)
    {
      auto maxi = max_element(S.begin(), S.end());
      flush(get<1>(*maxi), get<2>(*maxi));
      return 0;
    }
    vector<int> move;
    for (auto i = 0; i < T; i++)
    {
      move.push_back(mt() % 4);
    }
    S.push_back(make_state(move));
  }
}