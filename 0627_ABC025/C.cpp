// 未完成品。当然ACしない。RubyのほうはAC済み。

#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef vector< vector<int> > tab;

int b[2][3];
int c[3][2];

int fukasa(tab ary, int dep) {
  if (dep == 9) {
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
  } else {
    vector<int> shu;
    for (auto i=0; i<3; i++) {
      for (auto j=0; j<3; j++) {
        if (ary[i][j] == 0) {
          tab temp = tab(3, vector<int>(3));
          for (auto k=0; k<3; k++) {
            for (auto l=0; l<3; l++) {
              temp[k][l] = ary[k][l];
            }
          }
          temp[i][j] = ((dep%2 == 0) ? 1 : -1);
          shu.push_back(fukasa(temp, dep+1));
        }
      }
    }
    int ans = 0;
    if (dep == 0) {
      for (unsigned i=0; i<shu.size(); i++) {
        cout << shu[i] << endl;
      }
    }
    if (dep%2 == 0) {
      for (unsigned i=0; i<shu.size(); i++) {
        ans = -1000000;
        ans = max(ans, shu[i]);
      }
    } else {
      for (unsigned i=0; i<shu.size(); i++) {
        ans = 1000000;      
        ans = min(ans, shu[i]);
      }
    }
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
  // tab table = tab(3, vector<int>(3, 0));
  tab table = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int sa = fukasa(table, 0);
  cout << (wa+sa)/2 << endl;
  cout << (wa-sa)/2 << endl;
}
