#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int c(char a) {
  return a - 'a';
}

int main() {
  int N;
  cin >> N;
  int V[30][30];
  fill(&V[0][0], &V[0][0]+30*30, 0);
  bool there[30];
  fill(there, there+30, false);
  for (auto i=0; i<N; i++) {
    string S;
    cin >> S;
    int a = c(S[0]);
    int b = c(S[S.size()-1]);
    V[a][b]++;
    V[b][a]++;
    there[a] = there[b] = true;
  }
  vector< vector<int> > Con; // 連結成分
  for (auto i=0; i<30; i++) {
    if (there[i]) {
      stack<int> S;
      S.push(i);
      vector<int> tCon;
      while (!S.empty()) {
        int now = S.top();
        S.pop();
        if (there[now]) {
          there[now] = false;
          tCon.push_back(now);
          for (auto j=0; j<30; j++) {
            if (V[now][j] != 0 && there[j]) {
              S.push(j);
            }
          }
        }
      }
      Con.push_back(tCon);
    }
  }
  int sum[30];
  for (auto i=0; i<30; i++) {
    sum[i] = 0;
    for (auto j=0; j<30; j++) {
      sum[i] += V[i][j];
    }
  }
  int ans = 0;
  // cerr << "Con size " << Con.size() << endl;
  for (auto i=0; i<Con.size(); i++) {
    int odd = 0;
    for (auto j=0; j<Con[i].size(); j++) {
      // cerr << Con[i][j] << " has " << sum[Con[i][j]] << endl;
      if (sum[Con[i][j]] %2 == 1) {
        odd++;
      }
    }
    if (odd != 0) {
      ans += (odd/2-1);
    }
  }
  ans += Con.size()-1;
  cout << ans << endl;
}
