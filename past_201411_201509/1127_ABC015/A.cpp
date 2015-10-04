#include <iostream>
#include <string>
using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  if (A.size() > B.size()) {
    cout << A << endl;
  } else {
    cout << B << endl;
  }
}
