#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#include <random>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

ofstream fout("some.txt");
random_device rod;
mt19937 mt(rod()); // mt() で整数

int makerandom() {
  return mt()%100;
}

string query(string url) {

#ifdef _MSC_VER
// Windowsは同梱のcurl.exeを適当なフォルダに配置してcurlコマンドを使えるようにしておくこと。
    FILE *f = _popen(("C:\\bin\\curl.exe -s -k \"" + url + "\"").c_str(), "r");
#else
// Linux,MacOS,Cygwinはパッケージ管理システムなどでインストールしてcurlコマンドを使えるようにしておくこと。
    FILE *f = popen(("curl -s -k \"" + url + "\"").c_str(), "r");
#endif

    if (f == NULL) {
        perror("error!");
    }
    char buf[1024];
    string res;
    while (!feof(f)) {
        if (fgets(buf, 1024, f) == NULL) break;
        res += (string)(buf);
    }

#ifdef _MSC_VER
    _pclose(f);
#else
    pclose(f);
#endif

    return res;
}

vector<vector<int> > V = {{1,10,12,13,18,22,23,48},{39,0,3,5,7,8,9,11,14,19,20,21,25,26,27,31,32,33,35,36,37,40,41,43,44,45,46,47,49,50,51,52,53,54,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99},{48,6},{4,17,30,38,39},{29,42,55},{24,34},{2,15,16,28},{34}};

int basis = 155;

void Vinit() {
  V.clear();
  vector<int> W;
  for (auto i=0; i<100; i++) {
    W.push_back(i);
  }
  V.push_back(W);
}

bool critical = false;
int cnum = 0;

void Vrep() {
  string S = "";
  S += "{";
  for (auto xxx=0; xxx<V.size(); xxx++) {
    S += "{";
    for (auto yyy=0; yyy<V[xxx].size(); yyy++) {
      S += to_string(V[xxx][yyy]);
      if (yyy < V[xxx].size()-1) S += ",";
    }
    S += "}";
    if (xxx < V.size()-1) S += ",";
  }
  S += "}";
  cout << S << endl;
}

int main() {
  vector<int> X;
  vector<int> High;
  vector<int> Low;
  critical = false;
  bool parted = false;
  for (int i = 0; i < 10000; i++) {
    string token = "CDG2RHAJTA2GR6ZJ0OZ5RB1THV1JZCLX";    
    if (i%60 == 30) {
      string url = "https://game.coderunner.jp/info?token="
	+ token
	+ "&filter=all&style=text";
      cout << query(url) << endl;
    } else {
      // Vrep();
      if (critical && X.empty()) {
	goto EXIT;
      }
      if (!parted) {
	// cerr << "parted i=" << i << endl;
	X = V[0];
	// cerr << X.size() << endl;
	// cerr << X.size() << endl;
	V.erase(V.begin());
	parted = true;
	continue;
      }
      if (critical || X.empty()) {
	// cerr << "marged i=" << i << endl;
	if (critical) {
	  for (auto j=0; j<X.size(); j++) {
	    Low.push_back(X[j]);
	  }
	}
	X.clear();
	if (!High.empty()) V.push_back(High);
	if (!Low.empty()) V.push_back(Low);
	High.clear();
	Low.clear();
	parted = false;
	Vrep();
	continue;
      }
    EXIT:
      int skill = makerandom();
      if (critical) {
	skill = cnum;
      } else {
	// cerr << "skill" << endl;
	skill = X[0];
	X.erase(X.begin());
      }
      string url = "https://game.coderunner.jp/attack?token="
	+ token
	+ "&skill=" + to_string(skill); 
      int result = stoi(query(url));
      cout << skill << " " << result << endl;
      if (result == basis+5) {
	basis += 5;
      }
      if (basis == result) {
	Low.push_back(skill);
      } else if (!critical) {
	High.push_back(skill);
      }
      if (result >= 10000) {
	critical = true;
	cnum = skill;
      } else {
	critical = false;
      }
    }
    sleep(1);
  }
  return 0;
}
