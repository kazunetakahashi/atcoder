#include <iostream>
#include <string>
using namespace std;

string S[2] = { "Blue", "Red" };

int main() {
  int N;
  cin >> N;
  cout << S[N%2] << endl;
}
