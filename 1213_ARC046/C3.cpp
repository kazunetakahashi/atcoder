#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>
#include <set>
using namespace std;

typedef tuple<int, int> human;

map<int, vector<human> > X;
multiset<int> S;

int main() {
  int N, M;
  cin >> N >> M;
  for (auto i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    X[a].push_back(make_tuple(1, b));
  }
  for (auto i = 0; i < M; i++) {
    int c, d;
    cin >> c >> d;
    X[d].push_back(make_tuple(0, c));
  }
  auto it = X.begin();
  int ans = 0;
  while (it != X.end()) {
    // cerr << "visiting: " << (*it).first << endl;
    sort((*it).second.begin(), (*it).second.end());
    auto vit = (*it).second.begin();
    while (vit != (*it).second.end() &&
           get<0>(*vit) == 0) {
      S.insert(get<1>(*vit));
      // cerr << "woman " << get<1>(*vit) << " inserted" << endl;
      vit++;
    }
    while (vit != (*it).second.end()) {
      auto del = S.lower_bound(get<1>(*vit));
      // cerr << "man " << get<1>(*vit) << " considered" << endl;
      if (del != S.end()) {
        // cerr << "woman " << *del << " deleated" << endl;
        S.erase(del);
        ans++;
      }
      vit++;
    }
    it++;
  }
  cout << ans << endl;
}
