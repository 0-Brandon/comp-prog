#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

struct SegTree {
  int n;
  vector<ll> sum, lazy;
  SegTree(int n) : n(n), sum(4 * n, 0), lazy(4 * n, 1) {}

  void push(int v) {
    if (lazy[v] != 1) {
      sum[2 * v] = (sum[2 * v] * lazy[v]) % MOD;
      sum[2 * v + 1] = (sum[2 * v + 1] * lazy[v]) % MOD;
      lazy[2 * v] = (lazy[2 * v] * lazy[v]) % MOD;
      lazy[2 * v + 1] = (lazy[2 * v + 1] * lazy[v]) % MOD;
      lazy[v] = 1;
    }
  }

  void upd(int v, int tl, int tr, int pos, ll val) {
    if (tl == tr) {
      sum[v] = (sum[v] + val) % MOD;
    } else {
      push(v);
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        upd(2 * v, tl, tm, pos, val);
      else
        upd(2 * v + 1, tm + 1, tr, pos, val);
      sum[v] = (sum[2 * v] + sum[2 * v + 1]) % MOD;
    }
  }

  void rmul(int v, int tl, int tr, int l, int r, ll mul) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      sum[v] = (sum[v] * mul) % MOD;
      lazy[v] = (lazy[v] * mul) % MOD;
    } else {
      push(v);
      int tm = (tl + tr) / 2;
      rmul(2 * v, tl, tm, l, min(r, tm), mul);
      rmul(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, mul);
      sum[v] = (sum[2 * v] + sum[2 * v + 1]) % MOD;
    }
  }

  ll query(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return 0;
    if (l == tl && r == tr)
      return sum[v];
    push(v);
    int tm = (tl + tr) / 2;
    return (query(2 * v, tl, tm, l, min(r, tm)) +
            query(2 * v + 1, tm + 1, tr, max(l, tm + 1), r)) %
           MOD;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(false);
  int n;
  ll d;
  cin >> n >> d;
  vector<ll> p(n);
  vector<int> o(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i] >> o[i];
  }
  vector<int> coaches;
  for (int i = 0; i < n; i++) {
    if (o[i] == 1)
      coaches.push_back(i);
  }
  int m = coaches.size();
  if (m == 0) {
    cout << 0 << "\n";
    return 0;
  }
  SegTree st(m);
  vector<int> cidx(n, -1);
  for (int i = 0; i < m; i++) {
    cidx[coaches[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    if (o[i] == 1) {
      int idx = cidx[i];
      ll prevSum = st.query(1, 0, m - 1, 0, idx - 1);
      st.upd(1, 0, m - 1, idx, (1 + prevSum) % MOD);
    } else {
      ll minPos = p[i] - d;
      int rb =
          lower_bound(coaches.begin(), coaches.end(), i) - coaches.begin() - 1;
      if (rb < 0)
        continue;
      int lo = 0, hi = rb, lb = rb + 1;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (p[coaches[mid]] >= minPos) {
          lb = mid;
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      if (lb <= rb) {
        st.rmul(1, 0, m - 1, lb, rb, 2);
      }
    }
  }
  ll ans = st.query(1, 0, m - 1, 0, m - 1);
  cout << ans << "\n";
}
