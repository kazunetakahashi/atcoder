#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <string>

using namespace std;
typedef long long ll;

int main() {
  ll N, K, M, R;
  cin >> N >> K >> M >> R;
  ll S[110];
  for (auto i=0; i<N-1; i++) {
    cin >> S[i];
  }
  sort(S, S+N-1);
  reverse(S, S+N-1);
  ll sum = 0;
  for (auto i=0; i<K-1; i++) {
    sum += S[i];
  }
  ll need = R*K-sum;
  if (need > M) {
    cout << -1 << endl;
  } else if (K < N && need <= S[K-1]) {
    cout << 0 << endl;
  } else {
    cout << max(need, (ll)0) << endl;
  }
}
