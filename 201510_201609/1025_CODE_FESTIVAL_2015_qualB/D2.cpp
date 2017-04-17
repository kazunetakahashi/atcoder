#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#include <string>

using namespace std;
typedef long long ll;

const ll infty = 10000000000000000;

typedef tuple<ll, int, ll> koma; // start, bango, counter
typedef tuple<int, ll> komas; // bango, counter

int S[100010];
int C[100010];
ll ans[100010];
vector<koma> k;

priority_queue<komas, vector<komas>, greater<komas> > Q;

int main() {
  int N;
  cin >> N;
  for (auto i=0; i<N; i++) {
    cin >> S[i] >> C[i];
    S[i]--;
    k.push_back(make_tuple(S[i], i, C[i]));
  }
  sort(k.begin(), k.end());
  auto it = k.begin();
  ll now = 0;
  ll mokuhyo = infty;
  ll next = 0;
  bool kiroku;
  while (!(Q.empty()) || (it != k.end())) {
    mokuhyo = ((Q.empty()) ? infty : get<1>(Q.top()));
    next = ((it == k.end()) ? infty : get<0>(*it));
    kiroku = (next >= mokuhyo+now);
    if (kiroku) {
      komas y = Q.top();
      Q.pop();
      now = min(next, mokuhyo+now);
      ans[get<0>(y)] = now;
      //cerr << "now = " << now << ", ans[" << get<1>(y) << "] = " << now << endl;
    } else {
      if (!Q.empty()) {
        komas y = Q.top();
        Q.pop();
        get<1>(y) -= get<0>(*it) - now;
        Q.push(y);
      }
      now = min(next, mokuhyo+now);
      //cerr << "now = " << now << ", push = " << get<1>(*it) << endl;
      Q.push(make_tuple(get<1>(*it), get<2>(*it)));
      it++;
    }
  }
  for (auto i=0; i<N; i++) {
    cout << ans[i] << endl;
  }
}
