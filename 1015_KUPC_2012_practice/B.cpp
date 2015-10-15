#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  string a[110];
  for (auto i=0; i<N; i++) {
    cin >> a[i];
  }
  sort(a, a+N);
  reverse(a, a+N);
  string ans = "";
  for (auto i=0; i<N; i++) {
    ans += a[i];
  }
  cout << ans << endl;
}
