#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  if (N == 1 || N == 4 || (N > 5 && ((N%2 == 0) || (N%5 == 0) || (N%3 == 0)))) {
    cout << "Not Prime" << endl;
  } else {
    cout << "Prime" << endl;
  }
}
