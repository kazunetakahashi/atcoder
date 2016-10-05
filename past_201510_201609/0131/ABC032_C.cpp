#include <iostream>
using namespace std;

typedef long long ll;

ll s[100010];

int main() {
  int N;
  ll K;
  cin >> N >> K;
  for (auto i = 0; i < N; i++) {
    cin >> s[i];
  }
  for (auto i = 0; i < N; i++) {
    if (s[i] == 0) {
      cout << N << endl;
      return 0;
    }
  }
  int indi=0, indj=0;
  ll now = 1;
  int ans = 0;
  while (indj < N) {
    if (indi < indj && now <= K) {
      ans = max(ans, indj - indi);
    }
    if (indi == indj) {
      now *= s[indj];
      indj++;
    } else if (now > K) {
      now /= s[indi];
      indi++;
      continue;
    } else {
      now *= s[indj];
      indj++;
    }
    if (indi < indj && now <= K) {
      ans = max(ans, indj - indi);
    }
    //cerr << "now = " << now
    //     << ", indj = " << indj << ", indi = " << indi << endl;
  }
  cout << ans << endl;
}
