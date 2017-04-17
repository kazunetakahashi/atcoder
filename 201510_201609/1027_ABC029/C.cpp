#include <iostream>
#include <string>
using namespace std;

int N;

void dfs(string s) {
  if (s.size() == N) {
    cout << s << endl;
  } else {
    for (auto i=0; i<3; i++) {
      dfs(s + (char)('a'+i));
    }
  }
}

int main() {
  cin >> N;
  dfs("");
}
