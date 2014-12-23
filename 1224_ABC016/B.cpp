#include <iostream>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int p = A+B;
  int m = A-B;
  bool a = (p == C);
  bool b = (m == C);
  if (a && b) cout << "?" << endl;
  else if (a && !b) cout << "+" << endl;
  else if (!a && b) cout << "-" << endl;
  else cout << "!" << endl;
}
