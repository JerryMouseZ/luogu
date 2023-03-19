#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
  int N, T;
  cin >> N >> T;
  vector<pair<int, double>> holes(N);
  for (int i = 0; i < N; ++i) {
    cin >> holes[i].first >> holes[i].second;
    holes[i].second /= holes[i].first;
  }
  sort(holes.begin(), holes.end(), [](const pair<int, double> &a, const pair<int, double> &b){
       return a.second > b.second;
       });
  double res = 0;
  int i = 0;
  while (T) {
    if (T >= holes[i].first) {
      res += holes[i].first * holes[i].second;
      T -= holes[i].first;
    } else {
      res += T * holes[i].second;
      T = 0;
    }
    ++i;
  }
  cout << fixed << setprecision(2) << res << endl;
  return 0;
}

