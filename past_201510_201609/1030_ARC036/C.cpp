#include <string>
#include <iostream>
#include <cmath>
using namespace std;

int N, K;
string S;

int dfs(string s) {
  if (s.size() == N) {
    for (auto i=0; i<N; i++) {
      for (auto j=i; j<N; j++) {
        int sa = 0;
        for (auto k=i; k<=j; k++) {
          if (s[k] == '0') {
            sa--;
          } else {
            sa++;
          }
        }
        if (abs(sa) > K) {
          return 0;
        }
      }
    }
    return 1;
  } else {
    if (S[s.size()] == '?') {
      return dfs(s+"1") + dfs(s+"0");
    } else {
      return dfs(s+(char)S[s.size()]);
    }
  }
}

int main() {
  cin >> N >> K >> S;
  if (N > 30) return 0;
  cout << dfs("") << endl;
}
