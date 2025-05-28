#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;

void solve() {
  cin >> n >> k;
  priority_queue<int, vector<int>, greater<int>> differences;
  int previous = 0;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
	int x;
	cin >> x;
	x %= k;
	if (x > previous) {
  	differences.push(x - previous);
  	ans += differences.top();
  	differences.pop();
	} else {
  	differences.push(k + x - previous);
	}
	previous = x;
  }
  cout << ans << "\n";
}

int main() {
  int t;
  cin >> t;
  while (t--)
	solve();
}