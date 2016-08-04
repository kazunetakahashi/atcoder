#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int A[110];
  for (auto i = 0; i < M; i++) {
    cin >> A[i];
  }
  if (M == 1) {
    cout << A[0] << endl;
    if (A[0] > 1) {
      cout << 2 << endl;
      cout << A[0]-1 << " " << 1 << endl;
    } else {
      cout << 1 << endl;
      cout << 1 << endl;
    }
    return 0;
  }
  vector<int> odd;
  deque<int> even;
  for (auto i = 0; i < M; i++) {
    if (A[i]%2 != 0) {
      odd.push_back(A[i]);
    } else {
      even.push_back(A[i]);
    }
  }
  if (odd.size() >= 3) {
    cout << "Impossible" << endl;
    return 0;
  } else if (odd.size() == 2) {
    even.push_back(odd[0]);
    even.push_front(odd[1]);
  } else if (odd.size() == 1) {
    even.push_back(odd[0]);
  }
  vector<int> ans;
  for (auto it = even.begin(); it != even.end(); it++) {
    if (it == even.begin() && (*it != 1)) {
      ans.push_back((*it)-1);
    } else if (it != even.begin()) {
      ans.push_back(*it);
    }
  }
  ans[ans.size()-1]++;
  for (auto i = 0; i < (int)even.size(); i++) {
    cout << even[i];
    if (i != (int)even.size()-1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
  cout << ans.size() << endl;
  for (auto i = 0; i < (int)ans.size(); i++) {
    cout << ans[i];
    if (i != (int)ans.size()-1) {
      cout << " ";
    } else {
      cout << endl;
    }    
  }
}
