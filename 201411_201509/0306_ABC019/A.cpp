#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a[3];
  for (auto i=0; i<3; i++) {
    cin >> a[i];
  }
  sort(a, a+3);
  cout << a[1] << endl;
}
