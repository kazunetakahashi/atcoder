#include <iostream>
#include <stack>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a[200010];
  int mini_c = (1 << 30);
  for (auto i=0; i<N; i++) {
    cin >> a[i];
    if (mini_c > a[i]) mini_c = a[i];
  }
  stack<int> S;
  int ans = 1;
  S.push(mini_c);
  for (auto i=0; i<N; i++) {
    // cerr << "a[" << i << "] = " << a[i] << endl;
    while (S.top() > a[i]) {
      // cerr << S.top() << " popped" << endl;
      S.pop();
    }
    if (S.top() < a[i]) {
      // cerr << a[i] << " pushed" << endl;
      S.push(a[i]);
      ans++;
    }
  }
  cout << ans << endl;
}
