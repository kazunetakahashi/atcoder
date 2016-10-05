#include <iostream>
using namespace std;

int a = 5;
int b = 40;

int main() {
  cout << b << endl;
  for (auto i=0; i<b; i++) {
    for (auto j=0; j<b; j++) {
      if (i == j) {
        cout << "N";
      } else if (i <= a || j <= a) {
        cout << "Y";
      } else {
        cout << "N";
      }
    }
    cout << endl;
  }
}
