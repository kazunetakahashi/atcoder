#include <iostream>
using namespace std;

int M;
string N;

int keta[10]; // kata[s] = 10^s未満の1の出てくる回数

long long power(long long x, long long n) {
  if (n == 0) {
    return 1;
  } else if (n%2 == 1) {
    return (x * power(x, n-1));
  } else {
    long long half = power(x, n/2);
    return (half * half);
  }
}

void init() {
  keta[0] = 0;
  for (auto i=1; i<10; i++) {
    keta[i] = 10 * keta[i-1] + power(10, i-1);
    // cerr << "keta[" << i << "] = " << keta[i] << endl;
  }
}

int calc() {
  N = to_string(M+1);
  while (N.size() < 9) {
    N = "0" + N;
  }
  reverse(N.begin(), N.end());
  int ans = 0;
  for (auto i=8; i>=0; i--) {
    int ones = 0;
    int k = (N[i] - '0');
    for (auto j=8; j>i; j--) {
      if (N[j] == '1') ones++;
    }
    int tans = ones * k * power(10, i);
    if (i > 0) {
      tans += k * keta[i-1];
    }
    if (k >= 2) {
      tans += power(10, i);
    }
    ans += tans;
  }
  return ans;
}

int main() {
  init();
  // cin >> M;
  for (M=0; M<100; M++) {
    cout << "M = " << M << " : " << calc() << endl;
  }
}
