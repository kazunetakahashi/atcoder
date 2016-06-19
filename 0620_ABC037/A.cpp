#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  cout << max(C/A, C/B) << endl;
}
