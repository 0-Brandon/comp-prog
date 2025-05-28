#include <bits/stdc++.h>


using namespace std;
int main() {
    int N, K, md;
    cin >> N >> K >> md;
    Mint::set_mod(md);

    VV<Mint> dp(N + 1, V<Mint>(MX));
    dp[0][0] = 1;
    int s = 0;

    for (int i = 1; i <= N; ++i) {
        V<Mint> ps(i);
        s += i;
        for (int j = 0; j <= s * K; ++j) {
            int x = j % i;
            ps[x] += dp[i - 1][j];
            if (j - i * (K + 1) >= 0) ps[x] -= dp[i - 1][j - i * (K + 1)];
            dp[i][j] = ps[x];
        }
    }

    s = 0;

    for (int i = 1; i <= N; ++i) {
        s += i;
        int ans = 0;
        for (int t = 0; t <= s * K; ++t) {
            ans += dp[i - 1][t] * dp[N - i][t];
        }
        ans = ans * (K + 1) - 1;
        cout << ans.val() << endl;
    }
}