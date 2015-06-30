#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef vector< vector<int> > tab;

int b[2][3];
int c[3][2];

map<tab, int> scores;

int eval(tab ary) {
  int ans = 0;
  for (auto i=0; i<2; i++) {
    for (auto j=0; j<3; j++) {
      ans += b[i][j] * ary[i][j] * ary[i+1][j];
    }
  }
  for (auto i=0; i<3; i++) {
    for (auto j=0; j<2; j++) {
      ans += c[i][j] * ary[i][j] * ary[i][j+1];
    }
  }
  return ans;
}

int fukasa(tab ary, int dep) {
  if (dep == 9) {
    if (scores.find(ary) != scores.end()) {
      return scores[ary];
    }
    return eval(ary);
  } else {
    vector<int> scoreset;
    for (auto i=0; i<3; i++) {
      for (auto j=0; j<3; j++) {
        if (ary[i][j] == 0) {
          ary[i][j] = ((dep%2 == 0) ? 1 : -1);
          scoreset.push_back(fukasa(ary, dep+1));
          ary[i][j] = 0;
        }
      }
    }
    int ans = 0;
    ans = ((dep%2 == 0) ?
           *max_element(scoreset.begin(), scoreset.end())
           : *min_element(scoreset.begin(), scoreset.end()));
    scores[ary] = ans;
    return ans;
  }
}

int main() {
  int wa = 0;
  for (auto i=0; i<2; i++) {
    for (auto j=0; j<3; j++) {
      cin >> b[i][j];
      wa += b[i][j];
    }
  }
  for (auto i=0; i<3; i++) {
    for (auto j=0; j<2; j++) {
      cin >> c[i][j];
      wa += c[i][j];
    }
  }
  tab table = tab(3, vector<int>(3, 0));
  int sa = fukasa(table, 0);
  cout << (wa+sa)/2 << endl;
  cout << (wa-sa)/2 << endl;
}
