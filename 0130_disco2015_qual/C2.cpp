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
  A[0].insert(S);
  for (auto i = 0; i < K; i++) {
    string x = *(A[i].begin());
    set<string> T;
    for (auto j = 0; j < (int)x.size(); j++) {
      string t = x;
      t.erase(j, 1);
      T.insert(t);
    }
    A[i+1].insert(*(T.begin()));
  }
  for (auto i = 0; i < K; i++) {
    string x = *(A[i].begin());
    set<string> T;
    for (auto j = 0; j < (int)x.size(); j++) {
      string t = x;
      if (t[j] != 'a') {
        t[j] = 'a';
        A[i+1].insert(t);
        break;
      }
    }
  }
  for (auto i = 0; i < K; i++) {
    string x = *(A[i].begin());
    A[i+1].insert('a'+x);
  }
  cout << *(A[K].begin()) << endl;
}
