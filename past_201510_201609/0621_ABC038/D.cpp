#include <iostream>
#include <set>
using namespace std;

int N;
set<int> V[100010];

const int C = 350;
int T[C][C];
int U[C];

void update(int x, int a) {
  T[x/C][x%C] = max(T[x/C][x%C], a);
  U[x/C] = max(U[x/C], a);
}

int calc_max(int x) {
  int ans = -1;
  for (auto i = 0; i < x/C; i++) {
    ans = max(U[i], ans);
  }
  for (auto i = 0; i <= x%C; i++) {
    ans = max(T[x/C][i], ans);
  }
  return ans;
}

int main() {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    int w, h;
    cin >> w >> h;
    V[w].insert(-1 * h);
  }
  fill(&T[0][0], &T[0][0]+C*C, 0);
  fill(U, U+C, 0);
  for (auto i = 0; i < 100010; i++) {
    for (auto x : V[i]) {
      x = -1 * x;
      // cerr << "i = " << i << ", x = " << x << endl;
      update(x, calc_max(x-1) + 1);
    }
  }
  cout << calc_max(C*C-1) << endl;
}
