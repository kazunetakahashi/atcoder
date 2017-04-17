#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
  ll A;
  cin >> A;
  for (auto i = 10; i < 100000; i++) {
    string S = to_string(i);
    reverse(S.begin(), S.end());
    ll ans = 0;
    ll kitei = 1;
    for (unsigned j = 0; j < S.size(); j++) {
      ans += (S[j]-'0') * kitei;
      kitei *= i;
    }
    if (ans == A) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
