#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int N;
    cin>>N;
    vector<int> a(N), c(N);
    for (int i = 0; i<N; ++i)cin>>a[i]>>c[i];
    vector<int> ord;
    stack<pair<int, bool>> s;
    s.emplace(1, false);
    while (!s.empty()) {
        auto [node, vis] = s.top();
        s.pop();
        if (vis) {
            ord.push_back(node);
        } else {
            s.emplace(node, true);
            int l = 2 * node;
            int r = 2 * node + 1;
            if (r <= N) {
                s.emplace(r, false);
                s.emplace(l, false);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int m;
        cin >> m;
        const int INF = 1e18;
        vector<int> eq(N + 1, INF);
        vector<int> le(N + 1, INF);
        vector<int> ge(N + 1, INF);
        for (int cur : ord) {
            int ai = a[cur - 1];
            int ci = c[cur - 1];
            int l = 2 * cur;
            int r = 2 * cur + 1;
            if (l > N) {
                eq[cur] = (ai == m) ? 0 : ci;
                le[cur] = (ai <= m) ? 0 : ci;
                ge[cur] = (ai >= m) ? 0 : ci;
            } else {
                int cosm = (ai != m) ? ci : 0;
                int case1 = cosm + min(le[l] + ge[r], ge[l] + le[r]);
                int case2 = eq[l] + min(((ai <= m) ? 0LL : ci) + ge[r], ((ai >= m) ? 0LL : ci) + le[r]);
                int case3 = eq[r] + min(((ai <= m) ? 0LL : ci) + ge[l], ((ai >= m) ? 0LL : ci) + le[l]);
                eq[cur] = min({case1, case2, case3});
                
                int o1 = ((ai <= m) ? 0LL : ci) + min(le[l] + min({le[r], ge[r], eq[r]}), le[r] + min({le[l], ge[l], eq[l]}));
                int o2 = le[l] + le[r];
                le[cur] = min(o1, o2);
                
                o1 = ((ai >= m) ? 0LL : ci) + min(ge[l] + min({ge[r], le[r], eq[r]}), ge[r] + min({ge[l], le[l], eq[l]}));
                o2 = ge[l] + ge[r];
                ge[cur] = min(o1, o2);
            }
        }
        cout << (eq[1] < INF ? eq[1] : -1) << '\n';
    }
}