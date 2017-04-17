#include <iostream>
#include <iomanip>
using namespace std;

double p;
long long n;

double power(double q, long long m) {
  if (m==0) {
    return 1;
  }
  if (m%2 == 0) {
    double d = power(q, m/2);
    return d*d;
  }
  return q*power(q, m-1);
}

int main() {
  cerr << power(0.1, 1) << endl;
  cin >> p >> n;
  cout << setprecision(9) << fixed 
       << 0.5 * ( 1 - power(1-2*p, n) ) << endl;
}
