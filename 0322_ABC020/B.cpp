#include <iostream>
#include <string>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  S += T;
  cout << stoi(S) * 2 << endl;
}
