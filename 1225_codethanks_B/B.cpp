#include <iostream>
#include <algorithm>
using namespace std;

int m = -1;
void big(int l) {
  if (m < l) m = l;
}

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  big(A*B*C);
  big(A+B+C);
  big((A+B)*C);
  big(A*B+C);
  cout << m << endl;
}
