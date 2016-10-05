#include <iostream>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  if (n <= 2*k+1) {
    cout << "first" << endl;
  } else if (n%2 == 0) {
    cout << "second" << endl;
  } else {
    cout << "first" << endl;
  }
}
