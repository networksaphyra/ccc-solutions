#include <bits/stdc++.h>
#include <cstdint>
#define ll long long
using namespace std;
void solve() {
  ll n;
  cin >> n;
  ll row, col;
  cin >> row >> col;
  vector<vector<ll>> A(1028, vector<ll>(1028, LLONG_MAX));
  for (ll i=0; i<row; ++i) {
    for (ll j=0; j<col; ++j) {
      cin >> A[i][j];
    }
  }
  for (ll q=1; q<n; ++q) {
    cin >> row >> col;
    vector<vector<ll>> B(1028, vector<ll>(1028, LLONG_MAX));
    vector<vector<ll>> C(1028, vector<ll>(1028, LLONG_MAX));
    for (ll i=0; i<row; ++i) {
      for (ll j=0; j<col; ++j) {
        cin >> B[i][j];
      }
    }
    for (ll i=0; i<1028; ++i) {
      for (ll j=0; j<1028; ++j) {
        if (A[i][j]==LLONG_MAX) continue;
        ll cur=A[i][j];
        ll start_row=i*row;
        ll start_col=j*col;
        for (ll cur_row=start_row; cur_row<start_row+row; ++cur_row) {
          for (ll cur_col=start_col; cur_col<start_col+col; ++cur_col) {
            C[cur_row][cur_col]=cur * B[cur_row-start_row][cur_col-start_col];
          }
        }
      }
    }
      A=C;
  }

  // for (int i=0; i<1028; ++i) {
  //   bool ok=false;
  //   for (int j=0; j<1028; ++j) {
  //     if (A[i][j]==LLONG_MAX) continue;
  //     ok=true;
  //     cout << A[i][j] << " ";
  //   }
  //   if (ok==false) break;
  //   cout << "\n";
  // }
  // for (int i=0; i<10; ++i) cout << "-";
  // cout << "\n";

  ll max_element=LLONG_MIN, min_element=LLONG_MAX;
  ll row_sum_max=LLONG_MIN, row_sum_min=LLONG_MAX;

  for (ll i=0; i<1028; ++i) {
    ll cur_sum=0;
    bool valid=false;
    for (ll j=0; j<1028; ++j) {
      if (A[i][j]==LLONG_MAX) continue;
      valid=true;
      max_element=max(max_element, A[i][j]);
      min_element=min(min_element, A[i][j]);
      cur_sum+=A[i][j];
    }
    if (!valid) break;
    row_sum_max=max(row_sum_max, cur_sum);
    row_sum_min=min(row_sum_min, cur_sum);
  }

  ll col_sum_max=LLONG_MIN, col_sum_min=LLONG_MAX;
  for (ll j=0; j<1028; ++j) {
    bool valid=false;
    ll cur_sum=0;
    for (ll i=0; i<1028; ++i) {
      if (A[i][j]==LLONG_MAX) continue;
      valid=true;
      cur_sum+=A[i][j];
    }
    if (!valid) break;
    col_sum_max=max(col_sum_max, cur_sum);
    col_sum_min=min(col_sum_min, cur_sum);
  }

  cout << max_element << "\n";
  cout << min_element << "\n";
  cout << row_sum_max << "\n";
  cout << row_sum_min << "\n";
  cout << col_sum_max << "\n";
  cout << col_sum_min << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t=1;
  while (t--)
    solve();
}
