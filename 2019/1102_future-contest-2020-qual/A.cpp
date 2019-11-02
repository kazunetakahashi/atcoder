#define DEBUG 1
/**
 * File    : A.cpp
 * Author  : Kazune Takahashi
 * Created : 11/2/2019, 1:43:18 PM
 * Powered by Visual Studio Code
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <complex>
#include <tuple>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <functional>
#include <random>
#include <chrono>
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
using namespace std;

constexpr int MOD{40};

using Point = tuple<int, int>;
Point operator+(Point const &lhs, Point const &rhs)
{
  return Point((get<0>(lhs) + get<0>(rhs) + MOD) % MOD, (get<1>(lhs) + get<1>(rhs) + MOD) % MOD);
}

constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};
constexpr char direction[4] = {'U', 'D', 'L', 'R'};
constexpr int reverse_direction[4] = {1, 0, 3, 2};

enum class State
{
  Empty,
  Robot,
  Block,
  Goal,
  Invalid
};

class Field
{
public:
  static int N;
  int M, B;
  static vector<Point> V;
  static vector<vector<Point>> P;
  vector<vector<int>> D;
  vector<vector<State>> S;

  Field();
  void solve()
  {
    good_place();
    other_place();
    // fill_empty();
  }
  void flush();

  State get_state(Point const &p) const
  {
    return S[get<0>(p)][get<1>(p)];
  }

  State &set_state(Point const &p, State s)
  {
    return S[get<0>(p)][get<1>(p)] = s;
  }

  int get_direction(Point const &p) const
  {
    return D[get<0>(p)][get<1>(p)];
  }

  int &set_direction(Point const &p, int d)
  {
    return D[get<0>(p)][get<1>(p)] = d;
  }

private:
  void good_place();
  void other_place();
  void fill_empty();
};

int Field::N;
vector<Point> Field::V;
vector<vector<Point>> Field::P;

Field::Field()
{
  cin >> M >> B;
  D = vector<vector<int>>(N, vector<int>(N, -1));
  S = vector<vector<State>>(N, vector<State>(N, State::Empty));
  int gx, gy;
  cin >> gx >> gy;
  int x, y;
  char c;
  for (auto i = 0; i < M; i++)
  {
    cin >> x >> y >> c;
    S[x][y] = State::Robot;
  }
  for (auto i = 0; i < B; i++)
  {
    cin >> x >> y;
    S[x][y] = State::Block;
  }
  S[gx][gy] = State::Goal;
}

void Field::good_place()
{
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (S[i][j] == State::Robot)
      {
        for (auto k = 0; k < 4; k++)
        {
          Point p{P[i][j] + V[k]};
          State s{get_state(p)};
          if (s == State::Block || s == State::Robot)
          {
            D[i][j] = k;
            break;
          }
        }
      }
    }
  }
}

void Field::other_place()
{
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (S[i][j] == State::Robot && D[i][j] == -1)
      {
        for (auto k = 0; k < 4; k++)
        {
          Point p{P[i][j] + V[k]};
          int d{get_direction(p)};
          // State s{get_state(p)};
          if (d != -1)
          {
            D[i][j] = k;
            break;
          }
        }
        if (D[i][j] != -1)
        {
          continue;
        }
        for (auto k = 0; k < 4; k++)
        {
          Point p{P[i][j] + V[k]};
          // int d{get_direction(p)};
          State s{get_state(p)};
          if (s == State::Empty)
          {
            D[i][j] = k;
            if (get_direction(p) == -1)
            {
              set_direction(p, reverse_direction[k]);
            }
            break;
          }
        }
        assert(D[i][j] != -1);
      }
    }
  }
}

void Field::fill_empty()
{
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (D[i][j] == -1)
      {
        D[i][j] = 0;
      }
    }
  }
}

void Field::flush()
{
  int K{0};
  for (auto x = 0; x < N; x++)
  {
    for (auto y = 0; y < N; y++)
    {
      if (0 <= D[x][y] && D[x][y] < 4)
      {
        ++K;
      }
    }
  }
  cout << K << endl;
  for (auto x = 0; x < N; x++)
  {
    for (auto y = 0; y < N; y++)
    {
      if (0 <= D[x][y] && D[x][y] < 4)
      {
        cout << x << " " << y << " " << direction[D[x][y]] << endl;
      }
    }
  }
}

int main()
{
  cin >> Field::N;
  for (auto i = 0; i < 4; i++)
  {
    Field::V.push_back(Point{dy[i], dx[i]});
  }
  Field::P = vector<vector<Point>>(Field::N, vector<Point>(Field::N));
  for (auto i = 0; i < Field::N; i++)
  {
    for (auto j = 0; j < Field::N; j++)
    {
      Field::P[i][j] = Point{i, j};
    }
  }
  Field f;
  f.solve();
  f.flush();
}