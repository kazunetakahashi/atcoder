#include <iostream>
#include <string>
using namespace std;

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

long long under_count(long long N, long long x) {
  // N未満の自然数に、xが何個あるか。ただしxは1から9。
  // Nは10^16くらいまで
  long long ans = 0;
  for (auto i=0; i<16; i++) {
    ans += N/power(10, i+1) * power(10, i);
    long long y = N%power(10, i+1);
    if (power(10, i) * x < y && y <= power(10, i) * (x+1)) {
      ans += y - power(10, i) * x;
    } else if (power(10, i) * (x+1) < y) {
      ans += power(10, i);
    }
  }
  return ans;
}

int main() {
  long long N;
  cin >> N;
  cout << under_count(N+1, 1) << endl;
}
