#include <iostream>
using namespace std;

struct human {
  int l, r, s;
};

int n, x, m;
human X[10];
int ori[6];
int ans[6];
int maximum = -1;

void check() {
  for (auto i=0; i<m; i++) {
    int t = 0;
    for (auto j=X[i].l; j<=X[i].r; j++) {
      t += ori[j];
    }
    if (t != X[i].s) return;
  }
  int sum = 0;
  for (auto i=0; i<n; i++) {
    sum += ori[i];
  }
  if (maximum < sum) {
    maximum = sum;
    // cerr << "maximum = " << maximum << endl;
    for (auto i=0; i<n; i++) {
      ans[i] = ori[i];
    }
  }
}

void dfs(int depth, int y) {
  ori[depth] = y;
  if (depth == n-1) {
    /*
    for (auto i=0; i<n; i++) {
      cerr << ori[i];
      if (i == n-1) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
    */
    check();
  } else {
    for (auto i=0; i<=x; i++) {
      dfs(depth+1, i);
    }
  }
}

int main() {
  cin >> n >> x >> m;
  for (auto i=0; i<m; i++) {
    cin >> X[i].l >> X[i].r >> X[i].s;
    X[i].l--;
    X[i].r--;
  }
  for (auto i=0; i<=x; i++) {
    dfs(0, i);
  }
  if (maximum == -1) {
    cout << -1 << endl;
  } else {
    for (auto i=0; i<n; i++) {
      cout << ans[i];
      if (i == n-1) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }
}
