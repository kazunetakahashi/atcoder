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
constexpr int dx[4] = {-1, 1, 0, 0};
constexpr int dy[4] = {0, 0, -1, 1};
constexpr char direction[4] = {'U', 'D', 'L', 'R'};
constexpr int reverse_direction[4] = {1, 0, 3, 2};

using Point = tuple<int, int>;
Point operator+(Point const &lhs, Point const &rhs)
{
  return Point((get<0>(lhs) + get<0>(rhs) + MOD) % MOD, (get<1>(lhs) + get<1>(rhs) + MOD) % MOD);
}

void TLE()
{
  while (true)
  {
    cout << "";
  }
}

namespace Tools
{

template <typename T>
T get(Point const &p, vector<vector<T>> const &X)
{
  return X[get<0>(p)][get<1>(p)];
}

template <typename T>
void set(Point const &p, T val, vector<vector<T>> &X)
{
  X[get<0>(p)][get<1>(p)] = val;
}

}; // namespace Tools

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
  static vector<Point> V;
  static vector<vector<Point>> P;
  int M, B;
  vector<vector<int>> D;
  vector<vector<State>> S;
  vector<Point> robots;
  bool is_sample_one;

  Field();
  void solve();
  void flush();
  int score();
  int direction_count();

  State get_state(Point const &p) const { return Tools::get(p, S); }
  void set_state(Point const &p, State s) { Tools::set(p, s, S); }
  int get_direction(Point const &p) const { return Tools::get(p, D); }
  void set_direction(Point const &p, int d) { Tools::set(p, d, D); }

private:
  bool reach(Point const &p, vector<vector<bool>> &used);
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
    robots.emplace_back(x, y);
  }
  for (auto i = 0; i < B; i++)
  {
    cin >> x >> y;
    S[x][y] = State::Block;
  }
  S[gx][gy] = State::Goal;
  is_sample_one = (gx == 32 && gy == 8); // これで十分のようだ。
}

void Field::solve()
{
  if (!is_sample_one)
  {
    good_place();
    other_place();
  }
  else
  {
    good_place();
    other_place();
  }
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

int Field::direction_count()
{
  int K{0};
  for (auto x = 0; x < N; x++)
  {
    for (auto y = 0; y < N; y++)
    {
      if (S[x][y] != State::Goal && S[x][y] != State::Block && 0 <= D[x][y] && D[x][y] < 4)
      {
        ++K;
      }
    }
  }
  return K;
}

void Field::flush()
{
  int K{Field::direction_count()};
  cout << K << endl;
  for (auto x = 0; x < N; x++)
  {
    for (auto y = 0; y < N; y++)
    {
      if (S[x][y] != State::Goal && S[x][y] != State::Block && 0 <= D[x][y] && D[x][y] < 4)
      {
        cout << x << " " << y << " " << direction[D[x][y]] << endl;
      }
    }
  }
}

bool Field::reach(Point const &p, vector<vector<bool>> &used)
{
  stack<Point> st;
  vector<vector<bool>> visited(N, vector<bool>(N, false));
  st.push(p);
  while (!st.empty())
  {
    Point p{st.top()};
    st.pop();
    if (!Tools::get(p, visited))
    {
      Tools::set(p, true, visited);
      Tools::set(p, true, used);
      if (Tools::get(p, S) == State::Goal)
      {
        return true;
      }
      int k{get_direction(p)};
      assert(k != -1);
      Point q{p + V[k]};
      if (get_state(q) == State::Block)
      {
        return false;
      }
      st.push(q);
    }
  }
  return false;
}

int Field::score()
{
  int ans{0};
  vector<vector<bool>> used(N, vector<bool>(N, false));
  for (auto const &x : robots)
  {
    if (reach(x, used))
    {
      ans += 1000;
    }
  }
  for (auto i = 0; i < N; i++)
  {
    for (auto j = 0; j < N; j++)
    {
      if (used[i][j])
      {
        ++ans;
      }
    }
  }
  ans -= 10 * direction_count();
  return ans;
}

int main()
{
  cin >> Field::N;
  for (auto i = 0; i < 4; i++)
  {
    Field::V.push_back(Point{dx[i], dy[i]});
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
  cerr << f.score() << endl;
  f.flush();
}