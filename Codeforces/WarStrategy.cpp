#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll cost(ll L, ll R) {
  if (L == 0 && R == 0)
    return 0;
  if (L == 0)
    return 2 * R - 1;
  if (R == 0)
    return 2 * L - 1;
  return L + R + max(L, R) - 1;
}

bool canFortify(ll f, ll m, ll k, ll n) {
  ll need = f - 1;
  ll maxL = min(need, k - 1);
  ll maxR = min(need, n - k);
  for (ll L = max(0LL, need - maxR); L <= min(need, maxL); L++) {
    ll R = need - L;
    if (cost(L, R) <= m)
      return true;
  }
  return false;
}

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;
  ll lo = 1, hi = min(n, m + 1);
  ll ans = 1;
  while (lo <= hi) {
    ll mid = (lo + hi) / 2;
    if (canFortify(mid, m, k, n)) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
