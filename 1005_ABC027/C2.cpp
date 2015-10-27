#include <iostream>
using namespace std;

typedef long long ll;

ll N;

int depth() {
  ll M = N;
  int cnt = 0;
  while (M > 0) {
    M /= 2;
    cnt++;
  }
  return cnt;
}

int main() {
  cin >> N;
  int d = depth();
  bool t = (d%2 == 0);
  ll x = 1;
  int ans = 0;
  while (x <= N) {
    x = (t ? 2*x : 2*x+1);
    t = !t;
    ans++;
  }
  cout << ((ans%2 == 0) ? "Takahashi" : "Aoki") << endl;
}
