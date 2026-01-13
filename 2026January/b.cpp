#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct BIT {
  int n;
  vector<int> t;
  BIT(int n) : n(n), t(n + 2, 0) {}
  void add(int i) {
    for (i++; i <= n + 1; i += i & -i)
      t[i]++;
  }
  int query(int i) {
    int s = 0;
    for (i++; i > 0; i -= i & -i)
      s += t[i];
    return s;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());

  BIT bit(n);
  ll ans = 0;
  int pcnt = 0;
  int i = 0;
  while (i < n) {
    int j = i;
    while (j < n && a[j].first == a[i].first)
      j++;
    for (int k = i; k < j; k++) {
      int pos = a[k].second;
      int cntL = bit.query(pos - 1);
      int cntR = pcnt - cntL;
      ans += min(cntL, cntR);
    }
    for (int k = i; k < j; k++) {
      bit.add(a[k].second);
    }
    pcnt += (j - i);
    i = j;
  }
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--)
    solve();
}