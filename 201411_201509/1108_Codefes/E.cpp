#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int C = 3010;

vector<int> L[C], H[C];

int main() {
  int N;
  cin >> N;
  vector<int> R;
  for (auto i=0; i<N; i++) {
    int x;
    cin >> x;
    R.push_back(x);
  }
  for (auto i=0; i<N; i++) {
    for (auto j=i+1; j<N; j++) {
      if (R[i] < R[j]) {
	H[i].push_back(j);
      } else if (R[i] > R[j]) {
	L[i].push_back(j);
      }
    }
  }
  // cerr << "a" << endl;
  int LC[C], HC[C];
  fill(LC, LC+C, 0);
  fill(HC, HC+C, 0);
  for (auto i=0; i<N; i++) {
    for (auto j=0; j<L[i].size(); j++) {
      if (HC[i]+1 > LC[ L[i][j] ]) {
	LC[L[i][j]] = HC[i]+1;
	// cerr << "LC[" << L[i][j] << "] = " << LC[L[i][j]] << endl;
      }
    }
    for (auto j=0; j<H[i].size(); j++) {
      if (LC[i]+1 > HC[ H[i][j] ]) HC[H[i][j]] = LC[i]+1;
      // cerr << "HC[" << H[i][j] << "] = " << HC[H[i][j]] << endl;
    }
  }
  int ans = max(HC[N-1], LC[N-1]);
  if (ans+1 > 2) {
    cout << ans+1 << endl; 
  } else {
    cout << 0 << endl;
  }
}
