#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <set>
#include <cmath>
#include <iomanip>
using namespace std;

typedef tuple<int, int> soup;
typedef tuple<int, int> cup;

int main() {
  int N, X, Y;
  cin >> N >> X >> Y;
  int a[100], b[100];
  soup s[100];
  cup c[100];
  bool used[100];
  fill(used, used+100, false);
  for (auto i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
    s[i] = make_tuple(b[i], i);
    c[i] = make_tuple(a[i]+b[i], i);
  }
  sort(s, s+100);
  reverse(s, s+100);
  sort(c, c+100);
  reverse(c, c+100);
  int allb=0, allc=0;
  for (auto i = 0; i < N; i++) {
    allb += b[i];
    allc += a[i] + b[i];
  }
  if (allb < Y || allc < X+Y) {
    cout << "-1" << endl;
    return 0;
  } else {
    int ans = 0;
    int nowb = 0;
    int nowc = 0;
    int ind = 0;
    while (nowb < Y) {
      nowb += get<0>(s[ind]);
      nowc += a[get<1>(s[ind])] + b[get<1>(s[ind])];
      used[get<1>(s[ind])] = true;
      ind++;
      ans++;
    }
    ind = 0;
    while (nowc < X+Y) {
      if (!used[get<1>(c[ind])]) {
        nowc += get<0>(c[ind]);
        ans++;
      }
      ind++;
    }
    cout << ans << endl;
  }
}
