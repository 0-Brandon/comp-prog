#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n;
ll x;
ll t[MAXN];

// Compute LIS ending at each position
vector<int> compute_dp_end() {
    vector<ll> tails; // Smallest tail for each length
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        auto it = lower_bound(tails.begin(), tails.end(), t[i]);
        if (it == tails.end()) {
            tails.push_back(t[i]);
        } else {
            *it = t[i];
        }
        dp[i] = tails.size();
    }
    return dp;
}

// Compute LIS starting at each position (reverse sequence)
vector<int> compute_dp_start() {
    vector<ll> tails;
    vector<int> dp(n + 1, 0);
    for (int i = n; i >= 1; i--) {
        auto it = lower_bound(tails.begin(), tails.end(), t[i]);
        if (it == tails.end()) {
            tails.push_back(t[i]);
        } else {
            *it = t[i];
        }
        dp[i] = tails.size();
    }
    return dp;
}

// Fenwick Tree for maximum queries
struct Fenwick {
    vector<int> tree;
    Fenwick(int sz) : tree(sz + 1, 0) {}
    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            tree[idx] = max(tree[idx], val);
        }
    }
    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res = max(res, tree[idx]);
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    // Step 1: Compute dp_end and dp_start
    vector<int> dp_end = compute_dp_end();
    vector<int> dp_start = compute_dp_start();

    // Original LIS
    int ans = *max_element(dp_end.begin(), dp_end.end());

    // Step 2: Process each r, vary l
    for (int r = 1; r <= n; r++) {
        vector<ll> tails;
        int m = 0;
        ll min_lr = t[r];
        ll max_lr = t[r];

        // Fenwick Tree for a < l with t[a] < value
        Fenwick ft(n);
        for (int a = 1; a < r; a++) {
            ft.update(a, dp_end[a]);
        }

        // For current r, l = r
        tails.push_back(t[r]);
        m = 1;

        // For each b > r
        for (int b = r + 1; b <= n; b++) {
            ll c = min_lr - max_lr;
            ll threshold = t[b] + c;
            int max_dp_a = (r > 1) ? ft.query(r - 1) : 0;
            if (max_dp_a > 0 && t[1] <= threshold + x - 1 && t[b] >= max_lr - x + 1) {
                ans = max(ans, max_dp_a + m + dp_start[b]);
            }
        }

        // Decrease l from r-1 to 1
        for (int l = r - 1; l >= 1; l--) {
            // Update min_lr and max_lr
            min_lr = min(min_lr, t[l]);
            max_lr = max(max_lr, t[l]);

            // Update m for [l, r]
            auto it = lower_bound(tails.begin(), tails.end(), t[l]);
            if (it == tails.end()) {
                tails.push_back(t[l]);
                m = tails.size();
            } else {
                *it = t[l];
                m = tails.size();
            }

            // Update Fenwick Tree (remove position l)
            ft.update(l, dp_end[l]);

            // For each b > r
            for (int b = r + 1; b <= n; b++) {
                ll c = min_lr - max_lr;
                ll threshold = t[b] + c;
                int max_dp_a = ft.query(l - 1);
                if (max_dp_a > 0) {
                    // Check if d exists: t[a] < min_lr + d < t[b]
                    // d > t[a] - min_lr, d < t[b] - max_lr, -x < d < x
                    ll d_lower = t[l] - min_lr + 1; // Conservative, using l as a proxy
                    ll d_upper = t[b] - max_lr - 1;
                    if (d_lower <= d_upper && d_lower < x && d_upper > -x) {
                        ans = max(ans, max_dp_a + m + dp_start[b]);
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}