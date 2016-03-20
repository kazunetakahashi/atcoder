#include <iostream>
#include <vector>
using namespace std;

struct point {
  int x, y;
  point(int tx, int ty) {
    x = tx;
    y = ty;
  }
};

int A[30][30];
vector<point> ans;

void input() {
  for (auto i = 0; i < 30; i++) {
    for (auto j = 0; j < 30; j++) {
      cin >> A[i][j];
    }
  }
}

void output() {
  for (auto p : ans) {
    cout << p.x+1 << " " << p.y+1 << endl;
  }
}

void solve() {
  for (auto i = 0; i < 30; i++) {
    for (auto j = 0; j < 30; j++) {
      for (auto k = 0; k < A[i][j]; k++) {
        ans.push_back(point(i, j));
      }
    }
  }
}

int main() {
  input();
  solve();
  output();
}
