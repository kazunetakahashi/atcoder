#include <iostream>
using namespace std;

int main() {
  int N, Q;
  cin >> N >> Q;
  for (auto i=0; i<Q; i++) {
    int a, b, s, t;
    cin >> s >> t >> a >> b;
    int ans = b-a;
    int minus = min(t, b) - max(s, a);
    if (minus < 0) minus = 0;
    ans -= minus;
    if (ans < 0) ans = 0;
    cout << ans*100 << endl;
  }
}
