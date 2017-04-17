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

vector<vector<int> > V = {
  /* 0 */ {3, 22, 23, 30, 55, 61, 67, 73, 94, 97, 98},
  /* 1 */ {0, 14, 25, 35, 37, 63, 68, 75, 78, 80, 89, 90, 95},
  /* 2 */ {24, 70, 79},
  /* 4 */ {52, 54},
  /* 6 */ {28, 34, 43, 51, 66, 76},
  /* 7 */ {47, 72},
  /* 8 */ {4, 8, 9, 17, 26, 33, 36, 39, 45, 46, 53, 64, 70, 81, 82, 84},
  /* 10 */ {47, 67},
  /* 11 */ {87, 91},
  /* 12 */ {13, 71}
};

bool critical = false;
bool great = false;
bool rd = false;

void initst() {
  critical = false;
  great = false;
  rd = false;
}

bool tried[100];
unsigned int val = 0;
unsigned int cut = 0;
int cnum = 0;
int basis = 115;

void init() {
  fill(tried, tried+100, false);
  val = 0;
  cut = 0;
  cnum = 0;
  initst();
}

int main() {
  init();
  for (int i = 0; i < 10000; i++) {
    string token = "CDG2RHAJTA2GR6ZJ0OZ5RB1THV1JZCLX";    
    if (i%60 == 0) {
      string url = "https://game.coderunner.jp/info?token="
	+ token
	+ "&filter=all&style=text";
      cout << query(url) << endl;
    } else {
      int skill = makerandom();
      if (critical) {
	skill = cnum;
      }else if (true) {
	bool alltried = true;
	for (int i=0; i<100; i++) {
	  if (!tried[i]) {
	    skill = i;
	    alltried = false;
	    break;
	  }
	}
	if (alltried) {
	  init();
	  continue;
	}
      } else if (critical) {
	skill = cnum;
      } else if (great) {
	if (cut < V[val].size()) {
	  skill = V[val][cut];
	} else {
	  initst();
	  cut = 0;
	}
      } else {
	if (val < V.size()) {
	  skill = V[val][0];
	} else {
	  initst();
	  rd = true;
	}
      }
      string url = "https://game.coderunner.jp/attack?token="
	+ token
	+ "&skill=" + to_string(skill); 
      int result = stoi(query(url));
      cout << skill << " " << result << endl;
      if (result == basis+5) {
	basis += 5;
      }
      if (result >= 1000) {
	initst();
	critical = true;
	cnum = skill;
      } else if (result > basis) {
	initst();
	great = true;
	cut++;
      } else {
	if (great || critical) {
	  val = 0;
	  cut = 0;
	}
	critical = false;
	great = false;
	val++;
      }
      tried[skill] = true;
    }
    sleep(1);
  }
  return 0;
}
