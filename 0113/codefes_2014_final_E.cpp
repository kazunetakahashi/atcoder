// 誤答

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  int R[4000];
  for (auto i = 0; i < N; i++) {
    cin >> R[i];
  }
  vector<int> S;
  for (auto i = 0; i < N-1; i++) {
    int x = R[i+1] - R[i];
    if (x != 0) {
      S.push_back(x);
    }
  }
  int ans = 0;
  if (S.empty()) goto EXIT;
  for (auto it = S.begin(); it+1 != S.end(); it++) {
    if (*it * *(it+1) < 0) {
      ans++;
    }
  }
 EXIT:
  if (ans == 0) {
    cout << 0 << endl;
  } else {
    cout << ans+2 << endl;
  }
}
