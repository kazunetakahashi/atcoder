#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
  vector<string> V;
  string S;
  while (cin >> S) {
    V.push_back(S);
  }
  sort(V.begin(), V.end());
  cout << V[6] << endl;
}
