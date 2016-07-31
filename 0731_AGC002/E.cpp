#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int N;
  cin >> N;
  int a[100010];
  for (auto i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a, a+N);
  reverse(a, a+N);
  int ind = 0;
  while (ind+1 < N && ind+1 < a[ind+1]) {
    ind++;
  }
  cerr << ind << endl;
  int x = a[ind] - ind;
  int t = ind;
  while (t < N && a[t] > ind) {
    t++;
  }
  int y = t - ind;
  cerr << x << " " << y << endl;
  if (x % 2 != 0 && y % 2 != 0) {
    cout << "Second" << endl;
  } else {
    cout << "First" << endl;
  }
}
