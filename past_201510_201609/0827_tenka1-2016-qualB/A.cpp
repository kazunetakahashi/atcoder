#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

ll f(ll n) {
  return floor( ((double)n * n + 4.0) / 8.0);
}

int main() {
  cout << f(f(f(20))) << endl;
}
