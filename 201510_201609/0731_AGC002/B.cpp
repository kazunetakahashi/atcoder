#include <iostream>
#include <algorithm>
using namespace std;

int x[100010], y[100010];

int main() {
  int N, M;
  cin >> N >> M;
  for (auto i = 0; i < M; i++) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  bool red[100010];
  int sp[100010];
  fill(red, red+100010, false);
  red[0] = true;
  fill(sp, sp+100010, 1);
  for (auto i = 0; i < M; i++) {
    sp[x[i]]--;
    sp[y[i]]++;
    if (red[x[i]] && (sp[x[i]] > 0)) {
      red[y[i]] = true;
    } else if (red[x[i]] && (sp[x[i]] == 0)) {
      red[y[i]] = true;
      red[x[i]] = false;
    }
  }
  int ans = 0;
  for (auto i = 0; i < N; i++) {
    if (red[i]) {
      ans += 1;
    }
  }
  cout << ans << endl;
}

