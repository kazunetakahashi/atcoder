#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;
  cout << ((S[S.size()-1] == 'T') ? "YES" : "NO") << endl;
}
