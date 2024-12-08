#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  int sx, sy, sz;
  int tx, ty, tz;
  cin >> sx >> sy >> sz >> tx >> ty >> tz;

  int cur=0;
  vector<pair<int, int>> dirs={{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

  auto cube_root=[&](int x, int y, int z) {
    return sqrt((x-tx)*(x-tx)+(y-ty)*(y-ty)+(z-tz)*(z-tz));
  };
  double ans=cube_root(sx, sy, sz);
  while (true) {
    int forward;
    char dir;
    cin >> forward >> dir;


  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  // cin >> t;

  while (t--)
    solve();
}
