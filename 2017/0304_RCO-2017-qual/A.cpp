#include <iostream>
#include <iomanip> // << fixed << setprecision(xxx)
#include <algorithm> // do { } while ( next_permutation(A, A+xxx) ) ;
#include <vector>
#include <string> // to_string(nnn) // substr(m, n) // stoi(nnn)
#include <complex>
#include <tuple> // get<n>(xxx)
#include <queue>
#include <stack>
#include <map> // if (M.find(key) != M.end()) { }
#include <set> // S.insert(M);
// if (S.find(key) != S.end()) { }
// for (auto it=S.begin(); it != S.end(); it++) { }
// auto it = S.lower_bound(M);
#include <cctype>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib> // atoi(xxx)
#include <random>
using namespace std;

#define DEBUG 0 // change 0 -> 1 if we need debug.
// insert #if<tab> by my emacs. #if DEBUG == 1 ... #end

typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// const int C = 1e6+10;
// const ll M = 1000000007;

random_device rd;
mt19937 mt(rd());

typedef tuple<int, int> point;

int H, W, K;
int field[50][50];
bool used[50][50];
vector< vector<point> > answer;

bool valid(int x, int y) {
  return (0 <= x && x < H && 0 <= y && y < W
          && (field[x][y] > 0) && !used[x][y]);
}

bool valid(point p) {
  return valid(get<0>(p), get<1>(p));
}

void input() {
  cin >> H >> W >> K;
  for (auto i = 0; i < H; ++i) {
    string S;
    cin >> S;
    for (auto j = 0; j < W; ++j) {
      field[i][j] = (S[j] - '0');
    }
  }
  fill(&used[0][0], &used[0][0]+50*50, false);
}

string to_answer[4] = {"D", "R", "U", "L"};

void output() {
  cout << (int)answer.size() << endl;
  for (auto V : answer) {
    for (auto x : V) {
      cout << get<0>(x)+1 << " " << get<1>(x)+1 << endl;
    }
  }
}

void solve() {
  for (auto i = 0; i < 1e8; ++i) {
    point start(mt()%H, mt()%W);
    if (!valid(start)) continue;
    vector<point> V;
    V.push_back(start);
    used[get<0>(start)][get<1>(start)] = true;
    while ((int)V.size() < K) {
      bool ok = false;
      for (auto t = 0; t < 100; ++t) {
        int kv = mt()%((int)V.size());
        point now = V[kv];
        int k = mt()%4;
        point newpt(get<0>(now)+dx[k], get<1>(now)+dy[k]);
        if (valid(newpt)) {
          used[get<0>(newpt)][get<1>(newpt)] = true;
          V.push_back(newpt);
          now = newpt;
          ok = true;
          break;
        }
      }
      if (!ok) break;
    }
    if ((int)V.size() < K) {
      continue;
    } else {
      answer.push_back(V);
    }
  }
}

int main () {
  input();
  solve();
  output();
}
