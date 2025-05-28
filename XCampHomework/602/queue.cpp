#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 300005;

int cnt;
int n, m, q, t;
struct Node {
    int l, r, sum;
}node[N * 42];
int root[N],sz[N];
vector<int> ins[N];

void upd(int& id, int l, int r, int p, int val) {
    if (id == 0) id = ++cnt;
    if (l == r) {
        node[id].sum += val;
        return;
    }
    int mid = (l+r)/2;
    if (p <= mid) upd(node[id].l, l, mid, p, val);
    else upd(node[id].r, mid + 1, r, p, val);
    node[id].sum = node[node[id].l].sum + node[node[id].r].sum;
}

int query(int id, int l, int r, int k) {
    if (l==r) return l;
    int mid = (l+r)/2;
    int lsum = node[node[id].l].sum;
    if (l <= t) {
        lsum += (mid>t)?(t-l+1):(mid-l+1);
    }
    if (k <= lsum) return query(node[id].l, l, mid, k);
    else return query(node[id].r, mid + 1, r, k - lsum);
}
signed main() {
    cin.tie(0)->sync_with_stdio(false);
    cin>>n>>m>>q;
    int temp = q;
    while (temp--) {
        int x, y;
        cin>>x>>y;
        int ans = 0, tmp = 0;
        if (y == m) {
            t = n;
            ans = query(root[n + 1], 1, n + q, x);
            upd(root[n + 1], 1, n + q, ans, -1);
            upd(root[n + 1], 1, n + q, n + (++sz[n + 1]), 1);
            if (ans <= n) ans = ans * m;
            else ans = ins[n + 1][ans - n - 1];
            ins[n + 1].push_back(ans);
            cout<<ans<<"\n";
        } else {
            t = m - 1;
            ans = query(root[x], 1, m + q, y);
            upd(root[x], 1, m + q, ans, -1);
            upd(root[x], 1, m + q, m - 1 + (++sz[x]), 1);
            if (ans <= m - 1) ans += (x - 1) * m;
            else ans = ins[x][ans - m];
            t = n;
            tmp = query(root[n + 1], 1, n + q, x);
            upd(root[n + 1], 1, n + q, tmp, -1);
            upd(root[n + 1], 1, n + q, n + (++sz[n + 1]), 1);
            if (tmp <= n) tmp = tmp * m;
            else tmp = ins[n + 1][tmp - n - 1];
            ins[n + 1].push_back(ans);
            ins[x].push_back(tmp);
            cout<<ans<<"\n";
        }
    }
}