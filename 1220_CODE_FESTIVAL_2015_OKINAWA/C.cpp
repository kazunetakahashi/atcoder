#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
string c[50010][3];

int main() {
  cin >> N;
  for (auto i = 0; i < N; i++) {
    for (auto j = 0; j < 3; j++) {
      cin >> c[i][j];
    }
  }
  int nuki = 0;
  int m = 0, n = 0;
  for (auto i = 0; i < N; i++) {
    int cnt = 0;
    for (auto j = 0; j < 3; j++) {
      for (auto k = 0; k < 3; k++) {
        if (c[i][j][k] == '.') cnt++;
      }
    }
    nuki += cnt/3;
    if (c[i][0] == "###"
        && c[i][1] == "###"
        && c[i][2] == "###") {
      m++;
    } else if ((c[i][0] == "###"
                && c[i][1] == "###"
                && c[i][2] == "...")
               || (c[i][0] == "..."
                && c[i][1] == "###"
                && c[i][2] == "###")
               || (c[i][0] == "##."
                && c[i][1] == "##."
                && c[i][2] == "##.")
               || (c[i][0] == ".##"
                && c[i][1] == ".##"
                && c[i][2] == ".##")) {
      n++;
    } 
  }
  string sente, gote;
  if (nuki%2 == 0) {
    sente = "Snuke";
    gote = "Sothe";
  } else {
    sente = "Sothe";
    gote = "Snuke";
  }
  if (m%2 == 0) {
    cout << ((n%2 == 0) ? gote : sente) << endl;
  } else {
    cout << sente << endl;
  }
}
