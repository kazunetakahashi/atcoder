#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector< pair<int, int> > d; // dist, vertex
  int dist, vertex;
  for (auto i=2; i<=N; i++) {
    cout << "? " << 1 << " " << i << endl;
    cin >> dist;
    vertex = i;
    d.push_back(make_pair(dist, vertex));
  }
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  int a = d[0].second;
  d.clear();
  for (auto i=1; i<=N; i++) {
    if (i == a) continue;
    cout << "? " << a << " " << i << endl;
    cin >> dist;
    vertex = i;
    d.push_back(make_pair(dist, vertex));
  }
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  cout << "! " << d[0].first << endl;
}
