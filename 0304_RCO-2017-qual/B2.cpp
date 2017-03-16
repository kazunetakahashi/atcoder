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

int H, W, K;

typedef tuple<int, int> pt;

class point {
public:
  int x, y;
  int f, d;
  bool movable;
  bool used;

  point() {};
  point(int _x, int _y, int _f, int _d, bool _m)
    : x(_x), y(_y), f(_f), d(_d), movable(_m), used(true) {}
  
  int score(int t) {
    return f - t * d;
  }
  bool valid() {
    return (0 <= x && x < H && 0 <= y && y < W && movable);
  }
  pt delta(int k) {
    return pt(x + dx[k], y + dy[k]);
  }
  bool esa() {
    return (f != 0 || d != 0);
  }
};

point field[50][50];

bool valid(pt p) {
  int& x = get<0>(p);
  int& y = get<1>(p);
  return field[x][y].valid();
}

random_device rd;
mt19937 mt(rd());

int sr, sc;
int N;
int fr[2510];
int fc[2510];
int F[2510];
int D[2510];
vector< vector<int> > answer;

typedef tuple<int, int, int, int> pt_d; // d, f, x, y
typedef tuple<int, int, int, int> pt_f; // f, d, x, y
typedef tuple<int, int, int, int, int, int> state;
// t, x, y, prevx, prevy, prevk;

pt_d PT_D[2510];
pt_f PT_F[2510];

void input() {
  cin >> H >> W >> K >> sr >> sc;
  sr--;
  sc--;
  for (auto i = 0; i < H; ++i) {
    string S;
    cin >> S;
    for (auto j = 0; j < W; ++j) {
      field[i][j] = point(i, j, 0, 0, (S[j] == '.'));
    }
  }
  cin >> N;
  for (auto i = 0; i < N; ++i) {
    cin >> fr[i] >> fc[i] >> F[i] >> D[i];
    fr[i]--;
    fc[i]--;
    field[fr[i]][fc[i]].f = F[i];
    field[fr[i]][fc[i]].d = D[i];
    if (field[fr[i]][fc[i]].esa()) {
      field[fr[i]][fc[i]].used = false;
    }
    PT_D[i] = pt_d(D[i], F[i], fr[i], fc[i]);
    PT_F[i] = pt_d(F[i], D[i], fr[i], fc[i]);
  }
  sort(PT_D, PT_D+N);
  reverse(PT_D, PT_D+N);
  sort(PT_F, PT_F+N);
  reverse(PT_F, PT_F+N);
}

string to_answer[4] = {"D", "R", "U", "L"};

void output() {
  int answer_size = 0;
  for (auto V : answer) {
    for (auto x : V) {
      cout << to_answer[x];
      ++answer_size;
      if (answer_size >= K) goto EXIT;
    }
  }
  while (answer_size < K) {
    cout << "-";
    ++answer_size;
  }
 EXIT:
  cout << endl;
}

void solve() {
  /*
  vector<pt_d> aim;
  for (auto i = 0; i < N; ++i) {
    pt_f &x = PT_F[i];
    pt_d newpt = pt_d(get<1>(x), get<0>(x), get<2>(x), get<3>(x));
    aim.push_back(newpt);
  }
  sort(aim.begin(), aim.end());
  */
  pt src = pt(sr, sc);
  int T = 0;
  int cnt = 0;
  while (T < K && cnt < N) {
    queue<state> Q;
    bool visited[50][50];
    for (auto i = 0; i < H; ++i) {
      for (auto j = 0;  j < W; ++j) {
        visited[i][j] = false;
      }
    }
    state from[50][50];
    Q.push(state(T, get<0>(src), get<1>(src), -1, -1, -1));
    while (!Q.empty()) {
      state now = Q.front();
      int now_t = get<0>(now);
      int now_x = get<1>(now);
      int now_y = get<2>(now);
      //int now_prevx = get<3>(now);
      //int now_prevy = get<4>(now);
      //int now_prevk = get<5>(now);
      Q.pop();
      if (now_t > K) return;
      if (!visited[now_x][now_y]) {
        // cerr << now_t << ", " << now_x << ", " << now_y << endl;
        visited[now_x][now_y] = true;
        from[now_x][now_y] = now;
        if (!field[now_x][now_y].used) {
          vector<state> V;
          V.push_back(now);
          pt vpt(get<3>(*(V.end()-1)), get<4>(*(V.end()-1)));
          while (valid(vpt)) {
            V.push_back(from[get<0>(vpt)][get<1>(vpt)]);
            vpt = pt(get<3>(*(V.end()-1)), get<4>(*(V.end()-1)));
          }
          reverse(V.begin(), V.end());
          vector<int> K;
          for (auto it = V.begin()+1; it != V.end(); ++it) {
            int k = get<5>(*it);
            K.push_back(k);            
          }
          answer.push_back(K);
          field[now_x][now_y].used = true;
          ++cnt;
          src = pt(now_x, now_y);
          // cerr << now_x << ", " << now_y << endl;
          T = now_t;
          break;
        }
        for (auto k = 0; k < 4; ++k) {
          int new_x = now_x + dx[k];
          int new_y = now_y + dy[k];
          pt new_p(new_x, new_y);
          if (field[new_x][new_y].valid() && !visited[new_x][new_y]) {
            Q.push(state(now_t+1, new_x, new_y, now_x, now_y, k));
          }
        }
      }
    }
  }
}

int main () {
  input();
  solve();
  output();
}
