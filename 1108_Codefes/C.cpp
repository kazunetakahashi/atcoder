#include <iostream>
#include <string>
using namespace std;

long long f(int N) {
  string S = to_string(N);
  long long ret = 0;
  int X[20];
  for (auto i=0; i<S.size(); i++) {
    X[S.size()-1-i] = S[i] - '0';
  }
  long long J = 1;
  for (auto i=0; i<S.size(); i++) {
    ret += X[i] * J;
    J *= N;
  }
  return ret;
}

int main() {
  long long A;
  cin >> A;
  int ub = 10010;
  int lb = 0;
  while (ub - lb > 1) {
    int t = (ub+lb)/2;
    long long L = f(t);
    if (L > A) {
      ub = t;
    } else {
      lb = t;
    }
  }
  if (f(lb) == A && lb >= 10) {
    cout << lb << endl;
  } else {
    cout << -1 << endl;
  }
}
