#include <bits/stdc++.h>
#include <cmath>
#define ll long long

using namespace std;

void solve() {
  int n;
  cin >> n;

  int mn_year=2007-18;
  int mn_month=2;
  int mn_date=27;

  while (n--) {
    int year, month, date;
    cin >> year >> month >> date;

    if (year>mn_year) cout << "No\n";
    else if (year<mn_year) cout << "Yes\n";
    else {
      // year is equal check for month and date
      if (month<mn_month) cout << "Yes\n";
      else if (month>mn_month) cout << "No\n";
      else {
        // month is equal check for date
        if (date<=mn_date) cout << "Yes\n";
        else cout << "No\n";
      }
    }
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
