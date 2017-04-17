#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;

const int DEPTH = 4;
const int TIMES = 10000;

struct point {
  int x, y;
  point(int tx, int ty) {
    x = tx;
    y = ty;
  }
  bool operator==(const point& right) const {
    return x == right.x && y == right.y;
  }
};

struct pass {
  vector<point> V;
  int reduce;
  int turn;
  double hikaku;
  pass(vector<point> tV, int treduce, int tturn) {
    V = tV;
    reduce = treduce;
    turn = tturn;
    hikaku = (reduce - turn)/sqrt((int)V.size()); 
  }
  bool operator<(const pass& right) const {
    return hikaku < right.hikaku;
  }
};

const int infty = 1000000;
random_device rd;
mt19937 mt(rd());
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int A[30][30];
int A_sum = 0;
int red_sum = 0;
vector<point> result;

vector<point> P;
int T[1000];
int G[1000];
int reduce;
int turn;
bool actual = false;

int count_sub(int l, int r) {
  // cerr << "l = " << l << ", r = " << r << endl;
  int mini = infty;
  for (auto i = l; i < r; i++) {
    mini = min(mini, T[i]-G[i]);
  }
  for (auto i = l; i < r; i++) {
    G[i] += mini;
  }
  int ans = mini;
  bool temp[1000];
  temp[0] = false;
  for (auto i = l; i < r; i++) {
    temp[i-l+1] = (T[i] > G[i]);
  }
  temp[r-l+1] = false;
  bool now = false;
  int left, right;
  for (auto i = 0; i < r-l+2; i++) {
    if (!now && !temp[i]) {
      continue;
    } else if (!now && temp[i]) {
      now = true;
      left = l+i-1;
    } else if (now && temp[i]) {
      continue;
    } else {
      now = false;
      right = l+i-1;
      ans += count_sub(left, right);
    }
  }
  // cerr << "ans = " << ans << endl;
  if (actual) {
    for (auto i = 0; i < mini; i++) {
      for (auto j = l; j < r; j++) {
        result.push_back(P[j]);
        A[P[j].x][P[j].y]--;
        red_sum++;
      }
    }
  }
  return ans;
}

bool count(int r) {
  for (auto i = 0; i < r; i++) {
    G[i] = r-1-i;
  }
  reduce = 0;
  for (auto i = 0; i < r; i++) {
    if (T[i] - G[i] < 0) return false;
    reduce += T[i] - G[i];
  }
  turn = count_sub(0, r);
  return true;
}

void count_test() {
  int M;
  cin >> M;
  for (auto i = 0; i < M; i++) {
    cin >> T[i];
  }
  if (count(M)) {
    cerr << "reduce = " << reduce << ", turn = " << turn << endl;
  } else {
    cerr << "failed" << endl;
  }
}

vector<pass> Passes[30][30];
bool visited[30][30];

bool valid(int i, int j) {
  return 0 <= i && i < 30 && 0 <= j && j < 30 && !visited[i][j];
}

void make_pass(int i, int j) {
  int M = mt()%DEPTH+1;
  int now_i = i;
  int now_j = j;
  vector<point> V;
  V.push_back(point(now_i, now_j));
  for (auto k = 0; k < M-1; k++) {
    int r = mt()%4;
    now_i += dx[r];
    now_j += dy[r];
    if (!valid(now_i, now_j)) return;
    point tp = point(now_i, now_j);
    for (auto x : V) {
      if (tp == x) {
        return;
      }
    }
    V.push_back(tp);
  }
  for (auto i = 0; i < M; i++) {
    T[i] = A[V[i].x][V[i].y];
  }
  if (count(M)) {
    Passes[i][j].push_back(pass(V, reduce, turn));
  }
}

void input() {
  for (auto i = 0; i < 30; i++) {
    for (auto j = 0; j < 30; j++) {
      cin >> A[i][j];
      A_sum += A[i][j];
    }
  }
}

void output() {
  for (auto p : result) {
    cout << p.x+1 << " " << p.y+1 << endl;
  }
}

void solve() {
  while (A_sum > red_sum) {
    int maxi = 0;
    int max_i, max_j;
    for (auto i = 0; i < 30; i++) {
      for (auto j = 0; j < 30; j++) {        
        if (A[i][j] > maxi) {
          maxi = A[i][j];
          max_i = i;
          max_j = j;
        }
        visited[i][j] = (A[i][j] == 0);
        Passes[i][j].clear();
      }
    }
    vector<point> X;
    int now_i = max_i;
    int now_j = max_j;
    while (true) {
      for (auto i = 0; i < TIMES; i++) {
        make_pass(now_i, now_j);
      }
      pass maxi = *(Passes[now_i][now_j].begin());
      for (auto temp : Passes[now_i][now_j]) {
        maxi = max(temp, maxi);
      }
      if ((int)maxi.V.size() == 1) {
        if (X.empty()) {
          X = maxi.V;
        }
        break;
      }
      vector<point> tX;
      tX = X;
      auto it = maxi.V.begin();
      if (!tX.empty()) {
        it++;
      }
      for (; it != maxi.V.end(); it++) {
        tX.push_back(*it);
        visited[(*it).x][(*it).y] = true;
      }
      for (auto i = 0; i < (int)tX.size(); i++) {
        T[i] = A[tX[i].x][tX[i].y];
      }
      if (count((int)tX.size())) {
        X = tX;
        it = maxi.V.end()-1;
        now_i = (*it).x;
        now_j = (*it).y;
      } else {
        break;
      }
    }
    actual = true;
    P = X;
    /*
    cerr << "red_sum = " << red_sum << endl;
    for (auto temp : P) {
      cerr << "(" << temp.x << ", " << temp.y << ") ";
    }
    cerr << endl;
    */
    for (auto i = 0; i < (int)P.size(); i++) {
      T[i] = A[P[i].x][P[i].y];
    }
    count((int)P.size());
    actual = false;
  }
}

int main() {
  input();
  solve();
  output();
}
