#include <iostream>
using namespace std;

int h[300010];
int l[300010];
int r[300010];

int main() {
  int N;
  cin >> N;
  for (auto i=0; i<N; i++) {
    cin >> h[i];
  }
  l[0] = 0;
  for (auto i=1; i<N; i++) {
    if (h[i-1] < h[i]) {
      l[i] = l[i-1]+1;
    } else {
      l[i] = 0;
    }
  }
  r[N-1] = 0;
  for (auto i=N-2; i>=0; i--) {
    if (h[i+1] < h[i]) {
      r[i] = r[i+1]+1;
    } else {
      r[i] = 0;
    }
  }
  int ans = -1;
  for (auto i=0; i<N; i++) {
    ans = max(ans, l[i] + r[i]);
  }
  cout << ans+1 << endl;
}
