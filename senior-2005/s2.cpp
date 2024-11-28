#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  int col, row;
  int cur_col=0, cur_row=0;

  int x, y;
  cin >> x >> y;
  while (true) {
    cin >> col >> row;
    if (col==0 && row==0) break;
    cur_col+=col;
    cur_row+=row;

    cur_col=max(0, cur_col);
    cur_row=max(0, cur_row);

    cur_col=min(cur_col, x);
    cur_row=min(cur_row, y);

    cout << cur_col << " " << cur_row << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;

  while (t--)
    solve();
}
