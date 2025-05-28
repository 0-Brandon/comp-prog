#include <bits/stdc++.h>
using namespace std;


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int d = 0;
    while (d <= 500 && (k * d < n || k * d % 2 != n % 2 || d < 1 + ((k * d - n) / 2 + n - 1) / n * 2)) {
        d++;
    }
    if (d > 500) {
        cout << "-1\n";
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = 1 + ((k * d - n) / 2) / n * 2;
        if (i < (k * d - n) / 2 % n) {
            a[i] += 2;
        }
    }
    int ans = 0;
    for (int i = 0; i < d; i++) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(), [&](int i, int j) {
            return a[i] > a[j];
        });
        cout << "?";
        for (int j = 0; j < k; j++) {
            cout << " " << p[j] + 1;
            a[p[j]]--;
        }
        cout << endl;
        int res;
        cin >> res;
        ans ^= res;
    }
    cout << "! " << ans << endl;
}