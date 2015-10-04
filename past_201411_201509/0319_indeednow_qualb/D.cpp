// 題意を勘違いしておりました。
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N, C;
  cin >> N >> C;
  int seq[100010];
  int count[100010];
  fill(count, count+100010, 0);
  int all = 0;
  bool used[100010];
  fill(used, used+100010, false);
  for (auto i=0; i<N; i++) {
    cin >> seq[i];
  }
  int i=0, j=-1;
  while (all < C) {
    j++;
    count[seq[j]]++;
    if (!used[seq[j]]) {
      used[seq[j]] = true;
      all++;
    }
  }
  long long ans = 0;
  while (j < N) {
    ans += N-j;
    count[seq[i]]--;
    while (count[seq[i]] == 0 && j < N) {
      j++;
      count[seq[j]]++;
    }
    i++;
  }
  cout << ans << endl;
}
