#include <random>
#include <iostream>
#include <map>
#include <string>
using namespace std;

long long a, b;
map<int, string> M;

random_device rd;
mt19937 mt(rd());

int hash_S(string S) {
  long long h = 0;
  for (unsigned i=0; i<S.size(); i++) {
    h = (h * a + (S[i] - 'a' + 1)) % b;
  }
  return (int)h;
}

string rand_st() {
  string S = "";
  for (auto i=0; i<7; i++) {
    S += (char)(mt()%26 + 'a');
  }
  return S;
}

int main() {
  cin >> a >> b;
  string S;
  int h;
  while (true) {
    S = rand_st();
    h = hash_S(S);
    if (M.find(h) != M.end()) {
      string T = M[h];
      if (S == T) continue;
      for (auto i=0; i<100; i++) {
        string X = "";
        for (auto j=0; j<7; j++) {
          if (((i >> j) & 1) == 1) {
            X += S;
          } else {
            X += T;
          }
        }
        // cerr << hash_S(S) << endl;
        cout << X << endl;
      }
      return 0;
    } else {
      M[h] = S;
    }
  }
}
