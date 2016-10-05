#include <iostream>
using namespace std;

double eps = 0.0000000001;

int main() {
  int a, b;
  double max = 0;
  for (auto i=1; i<=40; i++) {
    for (auto j=1; j<=i; j++) {
      double temp = j - (double)j/(i-j+1) - (double)(i-j)/i;
      if (max + eps < temp) {
        max = temp;
        b = i;
        a = j;
      }
    }
  }
  cout << b << endl;
  for (auto i=0; i<b; i++) {
    for (auto j=0; j<b; j++) {
      if (i == j) {
        cout << "N";
      } else if (i >= a || j >= a) {
        cout << "Y";
      } else {
        cout << "N";
      }
    }
    cout << endl;
  }
}
