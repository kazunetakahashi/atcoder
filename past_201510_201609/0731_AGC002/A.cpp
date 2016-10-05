#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if (a > 0) {
    cout << "Positive" << endl;
  } else if (a <= 0 && b >= 0) {
    cout << "Zero" << endl;
  } else {
    cout << (((b-a)%2 != 0) ? "Positive" : "Negative") << endl;
  }
}
