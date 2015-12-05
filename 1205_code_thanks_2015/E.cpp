#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  for (auto i = 0; i < Q; i++) {
    string S, T;
    cin >> S >> T;
    string Sp = "";
    set<char> St;
    for (auto x : T) {
      St.insert(x);
    }
    for (auto x : S) {
      if (St.find(x) != St.end()) {
        Sp += x;
      }
    }
    if (Sp.find(T) != string::npos) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
