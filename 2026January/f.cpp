#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

struct Matrix {
  vector<vector<ll>> a;
  Matrix() : a(5, vector<ll>(5, 0)) {}
  Matrix operator*(const Matrix &o) {
    Matrix r;
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
        for (int k = 0; k < 5; k++)
          r.a[i][j] = (r.a[i][j] + a[i][k] * o.a[k][j]) % MOD;
    return r;
  }
};

Matrix expo(Matrix m, ll p) {
  Matrix r;
  for (int i = 0; i < 5; i++)
    r.a[i][i] = 1;
  while (p) {
    if (p & 1)
      r = r * m;
    m = m * m;
    p >>= 1;
  }
  return r;
}

int enc(int a, int b) {
  if (a == 0 && b == 0)
    return 0;
  if (a == 0 && b == 1)
    return 1;
  if (a == 1 && b == 0)
    return 2;
  if (a == 1 && b == 1)
    return 3;
  if (a == 2 && b == 0)
    return 4;
  return -1;
}

pair<int, int> dec(int s) {
  if (s == 0)
    return {0, 0};
  if (s == 1)
    return {0, 1};
  if (s == 2)
    return {1, 0};
  if (s == 3)
    return {1, 1};
  return {2, 0};
}

bool valid(int a, int b) {
  return a >= 0 && a <= 2 && b >= 0 && b <= 1 && a + b <= 2;
}

pair<int, int> add(int a, int b) {
  int na = a + 1;
  int nb = (b == 0) ? 0 : b - 1;
  return {na, nb};
}

pair<int, int> sub(int a, int b) {
  int nb = b + 1;
  int na = (a == 0) ? 0 : a - 1;
  if (a == 0)
    nb = b + 1;
  else {
    na = a - 1;
    nb = b + 1;
  }
  return {na, nb};
}

Matrix trans;

void build() {
  for (int s = 0; s < 5; s++) {
    auto [a, b] = dec(s);
    auto [na, nb] = add(a, b);
    if (valid(na, nb)) {
      int ns = enc(na, nb);
      if (ns >= 0)
        trans.a[s][ns] += 1;
    }
    tie(na, nb) = sub(a, b);
    if (valid(na, nb)) {
      int ns = enc(na, nb);
      if (ns >= 0)
        trans.a[s][ns] += 1;
    }
  }
}

void solve() {
  ll r, c, x;
  cin >> r >> c >> x;
  ll n = max(r, c);
  vector<pair<ll, int>> a(x);
  for (int i = 0; i < x; i++) {
    char v;
    ll r, c;
    cin >> v >> r >> c;
    ll pos = (r == 1) ? c : r;
    a[i] = {pos, v == '+' ? 1 : -1};
  }
  sort(a.begin(), a.end());

  vector<ll> dp(5, 0);
  dp[0] = 1;
  ll pos = 1;

  for (auto &[p, v] : a) {
    if (p > pos) {
      ll gap = p - pos;
      Matrix mat = expo(trans, gap);
      vector<ll> ndp(5, 0);
      for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
          ndp[j] = (ndp[j] + dp[i] * mat.a[i][j]) % MOD;
      dp = ndp;
    }
    vector<ll> ndp(5, 0);
    for (int s = 0; s < 5; s++) {
      if (dp[s] == 0)
        continue;
      auto [a, b] = dec(s);
      if (v == 1) {
        auto [na, nb] = add(a, b);
        if (valid(na, nb)) {
          int ns = enc(na, nb);
          if (ns >= 0)
            ndp[ns] = (ndp[ns] + dp[s]) % MOD;
        }
      } else {
        auto [na, nb] = sub(a, b);
        if (valid(na, nb)) {
          int ns = enc(na, nb);
          if (ns >= 0)
            ndp[ns] = (ndp[ns] + dp[s]) % MOD;
        }
      }
    }
    dp = ndp;
    pos = p + 1;
  }

  if (n >= pos) {
    ll gap = n - pos + 1;
    Matrix mat = expo(trans, gap);
    vector<ll> ndp(5, 0);
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 5; j++)
        ndp[j] = (ndp[j] + dp[i] * mat.a[i][j]) % MOD;
    dp = ndp;
  }

  ll ans = 0;
  for (int i = 0; i < 5; i++)
    ans = (ans + dp[i]) % MOD;
  cout << ans << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  build();
  int t;
  cin >> t;
  while (t--)
    solve();
}