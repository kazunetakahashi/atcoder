#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  if (S[2] == 'B') {
    cout << "Bachelor ";
  } else if (S[2] == 'M') {
    cout << "Master ";
  } else {
    cout << "Doctor ";
  }
  cout << S[0] << S[1] << endl;
}
