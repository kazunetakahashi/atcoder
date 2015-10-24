#include <iostream>
using namespace std;

typedef long long ll;

const int infty = 1000000;

int N;
ll A[100010];
ll B[100010];
int nissu[100010];
ll minmon[100010];
ll ans[100010];

int main() {
  cin >> N;
  for (auto i=0; i<N; i++) {
    cin >> A[i];
  }
  for (auto i=0; i<N; i++) {
    cin >> B[i];
    if (i > 0) B[i] = max(B[i-1], B[i]);
  }
  nissu[0] = 0;
  minmon[0] = 0;
  for (auto i=1; i<N+1; i++) {
    nissu[i] = nissu[i-1] + 1;
    minmon[i] = minmon[i-1] + A[i-1];
    if (minmon[i] < 0) {
      if (B[i-1] == 0) {
        nissu[i] = infty;
      } else {
        int hakusu = ((-1) * minmon[i] + B[i-1] - 1) / B[i-1];
        nissu[i] += hakusu;
        minmon[i] += hakusu * B[i-1];
      }
    }
  }
  for (auto i=0; i<N+1; i++) {
    if (nissu[i] > N) {
      ans[i] = -1;
    } else {
      ans[i] = minmon[i] + B[i] * (N-nissu[i]);
    }
  }
  ll res = 0;
  for (auto i=0; i<N+1; i++) {
    res = max(res, ans[i]);
  }
  cout << res << endl;
}
