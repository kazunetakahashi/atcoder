#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long long ll;

int main() {
  ll K, N;
  cin >> N >> K;
  pair<double, ll> L[1010];
  for (auto i = 0; i < N; i++) {
    ll w;
    double p;
    cin >> w >> p;
    L[i] = make_pair(p/100, w);
  }
  double lb = 0, ub = 100;
  for (auto i = 0; i < 100; i++) {
    double t = (lb+ub)/2;
    double amarisolt[1010];
    for (auto i = 0; i < N; i++) {
      amarisolt[i] = L[i].second * (L[i].first - t);
    }
    sort(amarisolt, amarisolt+N);
    reverse(amarisolt, amarisolt+N);
    double k = 0;
    for (auto i = 0; i < K; i++) {
      k += amarisolt[i];
    }
    if (k >= 0) {
      lb = t;
    } else {
      ub = t;
    }
  }
  cout << fixed << setprecision(12) << lb * 100 << endl;
}
