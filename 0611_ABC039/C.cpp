#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
using namespace std;

map<string, string> M;

int main() {
  string S;
  cin >> S;
  S = S.substr(0, 12);
  M["WBWBWWBWBWBW"] = "Do";
  M["WBWWBWBWBWWB"] = "Re";
  M["WWBWBWBWWBWB"] = "Mi";
  M["WBWBWBWWBWBW"] = "Fa";
  M["WBWBWWBWBWWB"] = "So";
  M["WBWWBWBWWBWB"] = "La";
  M["WWBWBWWBWBWB"] = "Si";
  cout << M[S] << endl;
}
