#include <iostream>
#include <tuple>
using namespace std;

int main() {
  int N, L, W;
  cin >> N >> L >> W;
  tuple<int, int, int> X[100010];
  int a, b;
  for (auto i=0; i<N; i++) {
    cin >> a >> b;
    X[i] = make_tuple(a, b, 0);
  }
  int latter = 0;
  get<2>(X[0]) = 0;
  for (auto i=1; i<N; i++) {
    while ((latter < i) &&
           ((get<2>(X[latter]) == -1) || (get<0>(X[i])-W > get<1>(X[latter])))) {
      /*cerr << "latter = " << latter << ", X[latter] = "
           << get<0>(X[latter]) << " "
           << get<1>(X[latter]) << " "
           << get<2>(X[latter]) << endl;*/
      latter++;
    }
    if ((i == latter) || get<1>(X[i])-W < get<0>(X[latter])) {
      get<2>(X[i]) = -1;
    } else {
      get<0>(X[i]) = max(get<0>(X[latter]) + W, get<0>(X[i]));
      get<2>(X[i]) = get<2>(X[latter]) + 1;
    }
  }
  cout << get<2>(X[N-1]) << endl;
}
