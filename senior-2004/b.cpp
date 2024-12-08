#include <algorithm>
#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  vector<int> score(n, 0);
  vector<int> worst_rank(n, 1);

  for (int q=0; q<k; ++q) {
    for (int i=0; i<n; ++i) {
      int a;
      cin >> a;
      score[i]+=a;
    }
    set<int> cur={score.begin(), score.end()};
    vector<int> score_2={cur.begin(), cur.end()};
    sort(begin(score_2), end(score_2));

    map<int, int> mp;
    for (int i=0; i<score_2.size(); ++i) {
      mp[score_2[i]]=score_2.size()-i;
    }

    for (int i=0; i<n; ++i) {
      worst_rank[i]=max(worst_rank[i], mp[score[i]]);
    }
  }

  int mx=*max_element(begin(score), end(score));
  for (int i=0; i<n; ++i) {
    if (score[i]==mx) {
      cout << "Yodeller " << i+1 << " is the TopYodeller: score " << score[i] << ", worst rank " << worst_rank[i] << "\n";
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
