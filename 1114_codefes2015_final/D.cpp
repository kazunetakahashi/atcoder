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
  int N;
  cin >> N;
  int S[100010];
  int T[100010];
  for (auto i=0; i<N; i++) {
    cin >> S[i] >> T[i];
  }
  int imos[100010];
  fill(imos, imos+100010, 0);
  for (auto i=0; i<N; i++) {
    imos[S[i]]++;
    imos[T[i]]--;
  }
  for (auto i=1; i<100010; i++) {
    imos[i] += imos[i-1];
  }
  int m = 0;
  for (auto i=0; i<100010; i++) {
    m = max(m, imos[i]);
  }
  int lb, ub;
  for (auto i=0; i<100010; i++) {
    if (imos[i] == m) {
      lb = i;
      break;
    }
  }
  for (auto i=100009; i>=0; i--) {
    if (imos[i] == m) {
      ub = i;
      break;
    }
  }
  for (auto i=0; i<N; i++) {
    if ((lb >= S[i]) && (ub < T[i])) {
      cout << m-1 << endl;
      return 0;
    }
  }
  cout << m << endl;
}
