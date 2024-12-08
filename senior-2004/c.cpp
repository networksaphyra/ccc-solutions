#include <bits/stdc++.h>
#include <cctype>
#define ll long long

using namespace std;

bool not_resolved(string a) {
  for (char i='A'; i<='J'; ++i) {
    if (a[0]==i) return true;
  }
  return false;
}

vector<int> get_numbers(string a, vector<vector<int>>& number_grid) {
  vector<int> ans;
  for (int i=0; i<a.size(); i+=3) {
    char first_char=a[i];
    int first=first_char-'A';
    int second=a[i+1]-'1';

    ans.push_back(number_grid[first][second]);
  }
  return ans;
}

void solve() {
  int row=10, col=9;

  vector<vector<bool>> resolved(row, vector<bool>(col, false));
  vector<vector<string>> grid(row, vector<string>(col));
  vector<vector<int>> number_grid(row, vector<int>(col, -1));

  for (int i=0; i<row; ++i) {
    for (int j=0; j<col; ++j) {
      cin >> grid[i][j];
      if (!not_resolved(grid[i][j])) {
        resolved[i][j]=true;
        number_grid[i][j]=stoi(grid[i][j]);
      }
    }
  }

  for (int _=0; _<900; ++_) {
    for (int i=0; i<row; ++i) {
      for (int j=0; j<col; ++j) {
        if (resolved[i][j]) continue;
        vector<int> numbers=get_numbers(grid[i][j], number_grid);
        int current=0;
        bool ok=true;
        for (int k=0; k<numbers.size(); ++k) {
          if (numbers[k]==-1) {
            ok=false;
            break;
          }
          current+=numbers[k];
        }
        // if (_==0) {
        //   for (int k=0; k<numbers.size(); ++k) {
        //     cout << numbers[k] << " ";
        //   }
        //   cout << "\n";
        // }
        if (ok) {
          resolved[i][j]=true;
          number_grid[i][j]=current;
        }
      }
    }
  }

  for (int i=0; i<row; ++i) {
    for (int j=0; j<col; ++j) {
      if (resolved[i][j]==false) {
        cout << "* ";
      } else {
        cout << number_grid[i][j] << " ";
      }
    }
    cout << "\n";
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
