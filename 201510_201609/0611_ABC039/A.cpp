#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  cout << 2 * (A*B + B*C + C*A) << endl;
}
