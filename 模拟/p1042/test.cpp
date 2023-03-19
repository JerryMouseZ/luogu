#include <bits/stdc++.h>
#include <vector>
using namespace std;
char s[2501][25];
int main()
{
  ios::sync_with_stdio(false);
  int wbase11 = 0, wbase21 = 0;
  int lbase11 = 0, lbase21 = 0;
  vector<pair<int, int>> lresults;
  int line = 0;
  while (cin >> s[line++]);
  for (int i = 0; i < line; ++i) {
    for (int j = 0; j < 25; ++j) {
      if (s[i][j] == 'E') {
        goto end;   
      }
      if (s[i][j] == 'W') {
        wbase11++;
        wbase21++;
        if (wbase11 >= 11 && wbase11 - lbase11 >= 2) {
          cout << wbase11 << ":" << lbase11 << endl;
          wbase11 = 0;
          lbase11 = 0;
        }
        if (wbase21 >= 21 && wbase21 - lbase21 >= 2) {
          lresults.push_back(pair<int, int>(wbase21, lbase21));
          wbase21 = 0;
          lbase21 = 0;
        }
      }
      if (s[i][j] == 'L') {
        lbase11++;
        lbase21++;
        if (lbase11 >= 11 && lbase11 - wbase11 >= 2) {
          cout << wbase11 << ":" << lbase11 << endl;
          wbase11 = 0;
          lbase11 = 0;
        }
        if (lbase21 >= 21 && lbase21 - wbase21 >= 2) {
          lresults.push_back(pair<int, int>(wbase21, lbase21));
          wbase21 = 0;
          lbase21 = 0;
        }
      }
    }
  }
end:

  cout << wbase11 << ":" << lbase11 << endl << endl;
  for (int i = 0; i < lresults.size(); ++i) {
    cout << lresults[i].first << ":" << lresults[i].second << endl;
  }
  cout << wbase21 << ":" << lbase21 << endl;
  return 0;
}

