#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<string> S;
  string t;
  while (cin >> t) {
    S.push_back(t);
  }
  for (int i=0; i<(int)(S.size())-2; i++) {
    if (S[i] == "not" && S[i+1] == "not" && S[i+2] != "not") {
      S.erase(S.begin()+i);
      S.erase(S.begin()+i);
      i=-1;
    }
  }
  for (auto i=0; i<S.size(); i++) {
    cout << S[i];
    if (i < S.size()-1) cout << " ";
  }
  cout << endl;
}
