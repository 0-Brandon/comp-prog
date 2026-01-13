#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
vector<int> a;
vector<bool> oncyc;
vector<int> cycid, cycpos, cycentry;
vector<vector<int>> cycles;
vector<vector<int>> radj;
vector<int> tin, tout, sub;
vector<int> eupar;
int timer = 0;

vector<int> treew;
vector<int> cyctw;
vector<set<int>> cych;

vector<ll> amt;
vector<bool> mark;
vector<int> val;
vector<ll> ans(3, 0);

struct BIT {
  int n;
  vector<ll> t;
  BIT(int n) : n(n), t(n + 2, 0) {}
  void add(int i, ll v) {
    for (i++; i <= n; i += i & -i)
      t[i] += v;
  }
  ll query(int i) {
    ll s = 0;
    for (i++; i > 0; i -= i & -i)
      s += t[i];
    return s;
  }
  ll range(int l, int r) {
    if (l > r)
      return 0;
    return query(r) - query(l - 1);
  }
};
BIT *bit;
BIT *cbit;
vector<int> cbitidx;
struct mSegTree {
  int n;
  vector<int> t;
  mSegTree(int n) : n(n), t(2 * n, -1) {}
  void upd(int p, int v) {
    for (t[p += n] = v; p > 1; p >>= 1)
      t[p >> 1] = max(t[p], t[p ^ 1]);
  }
  int query(int l, int r) {
    int res = -1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1)
        res = max(res, t[l++]);
      if (r & 1)
        res = max(res, t[--r]);
    }
    return res;
  }
};
mSegTree *hldst;

vector<int> head, sz, pos, rpos;
int curpos = 0;

void findcyc() {
  vector<int> state(n, 0);
  vector<int> st;
  oncyc.assign(n, false);
  cycid.assign(n, -1);
  cycpos.assign(n, -1);
  for (int start = 0; start < n; start++) {
    if (state[start] != 0)
      continue;
    st.clear();
    int cur = start;
    while (state[cur] == 0) {
      state[cur] = 1;
      st.push_back(cur);
      cur = a[cur];
    }
    if (state[cur] == 1) {
      int cid = cycles.size();
      vector<int> cyc;
      int p = 0;
      bool found = false;
      for (int i = 0; i < st.size(); i++) {
        if (st[i] == cur)
          found = true;
        if (found) {
          oncyc[st[i]] = true;
          cycid[st[i]] = cid;
          cycpos[st[i]] = p++;
          cyc.push_back(st[i]);
        }
      }
      cycles.push_back(cyc);
    }
    for (int v : st)
      state[v] = 2;
  }
}

void fce() {
  cycentry.assign(n, -1);
  for (int i = 0; i < n; i++)
    if (oncyc[i])
      cycentry[i] = i;
  vector<bool> vis(n, false);
  queue<int> q;
  for (int i = 0; i < n; i++)
    if (oncyc[i]) {
      vis[i] = true;
      q.push(i);
    }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : radj[u]) {
      if (!vis[v]) {
        vis[v] = true;
        cycentry[v] = cycentry[u];
        q.push(v);
      }
    }
  }
}

void dfssz(int u, int p) {
  sz[u] = 1;
  for (int &v : radj[u]) {
    if (!oncyc[v] && v != p) {
      dfssz(v, u);
      sz[u] += sz[v];
      if (sz[v] > sz[radj[u][0]] || oncyc[radj[u][0]])
        swap(v, radj[u][0]);
    }
  }
}

void dfs(int u, int p) {
  eupar[u] = p;
  tin[u] = timer++;
  sub[u] = 1;
  pos[u] = curpos++;
  rpos[pos[u]] = u;

  bool heavy = true;
  for (int v : radj[u]) {
    if (!oncyc[v]) {
      if (heavy) {
        head[v] = head[u];
        heavy = false;
      } else {
        head[v] = v;
      }
      dfs(v, u);
      sub[u] += sub[v];
    }
  }
  tout[u] = timer - 1;
}

void euler() {
  tin.assign(n, -1);
  tout.assign(n, -1);
  sub.assign(n, 0);
  eupar.assign(n, -1);
  head.assign(n, -1);
  sz.assign(n, 0);
  pos.assign(n, -1);
  rpos.assign(n, -1);
  timer = 0;
  curpos = 0;

  for (int i = 0; i < n; i++)
    if (oncyc[i])
      for (int v : radj[i])
        if (!oncyc[v])
          dfssz(v, i);

  for (int i = 0; i < n; i++)
    if (oncyc[i]) {
      head[i] = i;
      for (int v : radj[i]) {
        if (!oncyc[v]) {
          head[v] = v;
          dfs(v, i);
        }
      }
    }
}

int findanc(int u) {
  if (oncyc[u])
    return -1;
  while (u != -1 && !oncyc[u]) {
    int h = head[u];
    int apos = hldst->query(pos[h], pos[u] + 1);
    if (apos != -1)
      return rpos[apos];
    u = eupar[h];
  }
  return -1;
}

vector<int> cbitst;

void inittreew() {
  treew.assign(n, 0);
  cbitidx.assign(n, -1);
  cbitst.assign(cycles.size(), 0);

  int idx = 0;
  for (int k = 0; k < cycles.size(); k++) {
    cbitst[k] = idx;
    for (int node : cycles[k]) {
      cbitidx[node] = idx++;
    }
  }
  for (int i = 0; i < n; i++) {
    if (oncyc[i]) {
      for (int v : radj[i])
        if (!oncyc[v])
          treew[i] += sub[v];
    }
  }
  cbit = new BIT(idx);
  for (int i = 0; i < n; i++) {
    if (oncyc[i]) {
      cbit->add(cbitidx[i], treew[i]);
    }
  }
  cyctw.assign(cycles.size(), 0);
  for (int k = 0; k < cycles.size(); k++) {
    for (int node : cycles[k])
      cyctw[k] += treew[node];
  }
}

int arcl(int cid, int prev, int cur) {
  int l = cycles[cid].size();
  return (cur - prev + l) % l;
}

int arctreew(int cid, int prev, int cur) {
  int l = cycles[cid].size();
  if (l == 0)
    return 0;

  int start = cbitst[cid];

  int pidx = start + prev;
  int cidx = start + cur;
  if (cur == prev)
    return 0;
  if (cur > prev) {
    return cbit->range(pidx + 1, cidx);
  } else {
    return cbit->range(pidx + 1, start + l - 1) + cbit->range(start, cidx);
  }
}

int findhost(int cid, int pos) {
  if (cych[cid].empty())
    return -1;
  auto it = cych[cid].lower_bound(pos);
  if (it == cych[cid].end())
    it = cych[cid].begin();
  return cycles[cid][*it];
}

void addth(int c, int type) {
  mark[c] = true;
  val[c] = type;
  hldst->upd(pos[c], pos[c]);
  ll subcnt = bit->range(tin[c] + 1, tout[c]);
  amt[c] = sub[c] - subcnt;
  bit->add(tin[c], amt[c]);

  int p = findanc(c);
  if (p == c) {
    int pp = eupar[c];
    p = -1;
    if (pp != -1 && !oncyc[pp])
      p = findanc(pp);
  }

  if (p != -1) {
    amt[p] -= amt[c];
    bit->add(tin[p], -amt[c]);
    ans[val[p]] -= amt[c];
  } else {
    int entry = cycentry[c];
    treew[entry] -= amt[c];
    cbit->add(cbitidx[entry], -amt[c]);
    int cid = cycid[entry];
    cyctw[cid] -= amt[c];

    int cychost = findhost(cid, cycpos[entry]);
    if (cychost != -1) {
      amt[cychost] -= amt[c];
      ans[val[cychost]] -= amt[c];
    }
  }
  ans[type] += amt[c];
}

void addch(int c, int type) {
  mark[c] = true;
  val[c] = type;
  int cid = cycid[c];
  int pos = cycpos[c];
  int l = cycles[cid].size();
  if (cych[cid].empty()) {
    amt[c] = l + cyctw[cid];
  } else {
    auto it = cych[cid].lower_bound(pos);
    int nextp, prevp;
    if (it == cych[cid].end()) {
      nextp = *cych[cid].begin();
      prevp = *cych[cid].rbegin();
    } else {
      nextp = *it;
      if (it == cych[cid].begin())
        prevp = *cych[cid].rbegin();
      else {
        auto pit = it;
        --pit;
        prevp = *pit;
      }
    }
    int al = arcl(cid, prevp, pos);
    int aw = arctreew(cid, prevp, pos);
    amt[c] = al + aw;
    int nextn = cycles[cid][nextp];
    amt[nextn] -= amt[c];
    ans[val[nextn]] -= amt[c];
  }
  cych[cid].insert(pos);
  ans[type] += amt[c];
}

void changetype(int c, int i) {
  int a = val[c];
  if (a == i)
    return;
  ans[a] -= amt[c];
  val[c] = i;
  ans[i] += amt[c];
}

void upd(int c, char ch) {
  int type = (ch == 'C' ? 0 : (ch == 'O' ? 1 : 2));
  if (mark[c])
    changetype(c, type);
  else if (oncyc[c])
    addch(c, type);
  else
    addth(c, type);
}

int main() {
  cin.tie(0)->sync_with_stdio(false);
  cin >> n;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  radj.resize(n);
  for (int i = 0; i < n; i++)
    radj[a[i]].push_back(i);
  findcyc();
  fce();
  euler();
  inittreew();

  bit = new BIT(n);
  hldst = new mSegTree(n);
  cych.resize(cycles.size());
  amt.assign(n, 0);
  mark.assign(n, false);
  val.assign(n, -1);
  cin >> m;
  while (m--) {
    int c;
    char ch;
    cin >> c >> ch;
    c--;
    upd(c, ch);
    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
  }
}