#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a[1010];
  for (auto i=0; i<N; i++) {
    cin >> a[i];
  }
  sort(a, a+N);
  int ans = 0;
  int sum = 0;
  for (auto i=0; i<N; i++) {
    if (a[i] > sum) {
      sum += a[i];
      ans++;
    }
  }
  cout << ans << endl;
}
