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

int H, W, K;
int sr, sc;
bool field[50][50];
int N;
int fr[2510];
int fc[2510];
int F[2510];
int D[2510];
vector<int> answer;

bool valid(int x, int y) {
  return (0 <= x && x < H && 0 <= y && y < W && field[x][y]);
}

void input() {
  cin >> H >> W >> K >> sr >> sc;
  sr--;
  sc--;
  for (auto i = 0; i < H; ++i) {
    string S;
    cin >> S;
    for (auto j = 0; j < W; ++j) {
      field[i][j] = (S[j] == '.');
    }
  }
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> fr[i] >> fc[i] >> F[i] >> D[i];
    fr[i]--;
    fc[i]--;
  }
}

string to_answer[4] = {"D", "R", "U", "L"};

void output() {
  for (auto i = 0; i < K; ++i) {
    if ((int)answer.size() <= i) {
      cout << "-";
    } else {
      cout << to_answer[answer[i]];
    }
  }
  cout << endl;
}

void solve() {
  int now_x = sr;
  int now_y = sc;
  for (auto i = 0; i < K; ++i) {
    bool ok = false;
    for (auto j = 0; j < 100; ++j) {
      int k = mt()%4;
      int new_x = now_x + dx[k];
      int new_y = now_y + dy[k];
      if (valid(new_x, new_y)) {
        answer.push_back(k);
        now_x = new_x;
        now_y = new_y;
        ok = true;
        break;
      } else {
      }
    }
    if (!ok) {
      return;
    }
  }
}

int main () {
  input();
  solve();
  output();
}
