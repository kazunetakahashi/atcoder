#include <iostream>
using namespace std;

typedef long long ll;

int X, P, A, B;

ll pw(int a) {
  if (a == 0) return 1;
  if (a%2 == 1) return (pw(a-1) * X)%P;
  ll b = pw(a/2);
  return (b*b)%P;
}

void answer() {
  cin >> X >> P >> A >> B;
  ll ans = P;
  for (auto i=A; i<B; i++) {
    ans = min(ans, pw(i));
    if (ans == 1) break;
  }
  cout << ans << endl;
}

int main() {
  for (auto i=0; i<10000; i++) {
    cout << "i = " << i << " ";
    answer();
  }
}
