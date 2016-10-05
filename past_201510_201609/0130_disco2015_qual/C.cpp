#include <iostream>
#include <string>
#include <set>
using namespace std;

typedef long long ll;

set<string> A[1010];

int main() {
  string S;
  cin >> S;
  int K;
  cin >> K;
  if (S.size() > 1000) return 0;
  A[0].insert(S);
  for (auto i = 0; i < K; i++) {
    for (auto x : A[i]) {
      for (auto j = 0; j < (int)x.size(); j++) {
        string t = x;
        t.erase(j, 1);
        A[i+1].insert(t);
      }
      for (auto j = 0; j < (int)x.size(); j++) {
        string t = x;
        t[j] = 'a';
        A[i+1].insert(t);
      }
      for (auto j = 0; j < (int)x.size(); j++) {
        string t;
        t = x.substr(0, j) + 'a' + x.substr(j);
        A[i+1].insert(t);
      }
    }
    cerr << "i = " << i << endl;
    for (auto x : A[i+1]) {
      cerr << x << endl;
    }
  }
  cout << *(A[K].begin()) << endl;
}
