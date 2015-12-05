#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  int s[100];
  for (auto i = 0; i < N; i++) {
    cin >> s[i];
  }
  int M;
  cin >> M;
  int a[5010];
  int b[5010];
  int c[5010];
  for (auto i = 0; i < M; i++) {
    cin >> a[i] >> b[i] >> c[i];
    b[i]--;
    c[i]--;
  }
  int sum = 0;
  for (auto i = 0; i < N; i++) {
    sum += s[i];
  }
  bool known[60][60];
  fill(&known[0][0], &known[0][0]+60*60, false);
  for (auto i = 0; i < N; i++) {
    known[i][i] = true;
  }
  for (auto i = 0; i < M; i++) {
    if (a[i] == 0) {
      known[b[i]][c[i]] = true;
    } else {
      int mini = sum;
      int maxi = sum;
      if (known[b[i]][c[i]]) {
        mini = maxi = s[c[i]];
      } else {
        for (auto j = 0; j < N; j++) {
          if (j == c[i]) continue;
          if (known[b[i]][j]) {
            mini -= s[j];
            maxi -= s[j];
          } else {
            mini -= 100;
            maxi -= 0;
          }
        }
        mini = max(mini, 0);
        maxi = min(100, maxi);
      }
      cout << mini << " " << maxi << endl;
    }
  }
}
