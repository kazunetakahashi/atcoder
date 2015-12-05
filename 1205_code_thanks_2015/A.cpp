#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  cout << abs(A) + abs(A-B) + abs(B) << endl;
}
