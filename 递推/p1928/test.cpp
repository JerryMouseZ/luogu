#include <bits/stdc++.h>
#include <cctype>
using namespace std;

string decode(const string &str, int &i) {
  string res;
  while (i < str.size()) {
    if (str[i] == '[') {
      int num = 0;
      ++i;
      while (isdigit(str[i])) {
        num *= 10;
        num += str[i] - '0';
        ++i;
      }
      string tmp = decode(str, i);
      for (int j = 0; j < num; ++j)
        res += tmp;
    } else if (str[i] == ']') {
      ++i;
      return res;
    } else {
      res.push_back(str[i]);
      ++i;
    }
  }
  return res;
}

int main()
{
  string str;
  cin >> str;
  int i = 0;
  cout << decode(str, i) << endl;
  return 0;
}

