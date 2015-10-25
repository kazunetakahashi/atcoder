#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

typedef pair<ll, bool> plane;
vector<plane> V;

int main() {
  ll N, M;
  cin >> N >> M;
  ll X, Y;
  cin >> X >> Y;
  ll a, b;
  for (auto i=0; i<N; i++) {
    cin >> a;
    V.push_back(make_pair(a, true));
  }
  for (auto i=0; i<M; i++) {
    cin >> b;
    V.push_back(make_pair(b, false));
  }
  sort(V.begin(), V.end());
  ll now = 0;
  bool port = true;
  ll ans = 0;
  for (int i=0; i<(int)V.size(); i++) {
    plane x = V[i];
    if ((port == x.second) && (now <= x.first)) {
      ans++;
      now = x.first + (port ? X : Y);
      //cerr << "port = " << port << ", now = " << now << endl;
      port = !port;
    }
  }
  cout << ans/2 << endl;
}
