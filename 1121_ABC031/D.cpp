#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int K, N;
string v[60];
string w[60];
string k[3];
vector<string> V[4];
vector<string> W;
bool cleared = false;

bool solve() {
  for (auto i=0; i<N; i++) {
    string temp = "";
    for (auto c : v[i]) {
      temp += k[c-'1'];
    }
    if (temp != w[i]) {
      return false;
    }
  }
  return true;
}

void dfs(int x) {
  if (x == 3) {
    if (solve() && !cleared) {
      for (auto i=0; i<K; i++) {
        cout << k[i] << endl;
      }
      cleared = true;
    }
  }
  else {
    for (auto s : W) {
      k[x] = s;
      dfs(x+1);
    }
  }
}

int main() {
  cin >> K >> N;
  for (auto i=0; i<N; i++) {
    cin >> v[i] >> w[i];
  }
  V[0].push_back("");
  for (auto i=0; i<3; i++) {
    for (auto s : V[i]) {
      V[i+1].push_back(s + "a");
      V[i+1].push_back(s + "b");
      V[i+1].push_back(s + "c");
    }
  }
  for (auto i=0; i<4; i++) {
    for (auto s : V[i]) {
      W.push_back(s);
    }
  }
  dfs(0);
}
