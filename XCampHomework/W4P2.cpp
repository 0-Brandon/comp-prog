#include <bits/stdc++.h>

#define int long long
using namespace std;

const int MOD = 1e9+7;

int id(int a, int b) {
    if(a==b)return 1;
    if(a<b)return 0;
    return 2;
}
vector<vector<int>> solve(vector<int>& limit, vector<int>& digits) {
    vector<vector<int>> answers(digits.size(),vector<int>(digits.size()));
    for (int j = 0; j < digits.size(); j++) {
        vector<vector<vector<int>>> dp(limit.size(), vector<vector<int>>(limit.size(), vector<int>(3, 0)));
        for (int k = j; k < digits.size(); k++) {
            for (int x = 0; x < limit.size(); x++) {
                for (int y = limit.size() - 1; y > x; y--) {
                    if (digits[k] > limit[x]) {
                        for (int c = 0; c <= 2; c++) {
                            dp[x][y][2] = (dp[x][y][2] + dp[x + 1][y][c]) % MOD;
                        }
                    } else if (digits[k] == limit[x]) {
                        for (int c = 0; c <= 2; c++) {
                            dp[x][y][c] = (dp[x][y][c] + dp[x + 1][y][c]) % MOD;
                        }
                    } else {
                        for (int c = 0; c <= 2; c++) {
                            dp[x][y][0] = (dp[x][y][0] + dp[x + 1][y][c]) % MOD;
                        }
                    }

                    dp[x][y][2] = (dp[x][y][2] + dp[x][y - 1][2]) % MOD;
                    dp[x][y][id(digits[k], limit[y])] = (dp[x][y][id(digits[k], limit[y])] + dp[x][y - 1][1]) % MOD;
                    dp[x][y][0] = (dp[x][y][0] + dp[x][y - 1][0]) % MOD;
                }
            }
            for (int x = 0; x < limit.size(); x++) {
                dp[x][x][id(digits[k], limit[x])] = (dp[x][x][id(digits[k], limit[x])] + 2) % MOD;
            }

            for (int x = 0; x < limit.size(); x++) {
                answers[j][k] = (answers[j][k] + dp[x][limit.size() - 1][0]) % MOD;
                answers[j][k] = (answers[j][k] + dp[x][limit.size() - 1][1]) % MOD;
                if (x != 0) {
                    answers[j][k] = (answers[j][k] + dp[x][limit.size() - 1][2]) % MOD;
                }
            }
        }
    }
    return answers;
}

signed main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> x(n);
    for(int i=0; i<n; i++)cin>>x[i];
    vector<int> ba;
    while(b){
        ba.push_back(b%10);
        b/=10;
    }
    reverse(ba.begin(),ba.end());
    vector<vector<int>> answersRight = solve(ba, x);
    ba.clear();
    a--;
    while(a){
        ba.push_back(a%10);
        a/=10;
    }
    reverse(ba.begin(),ba.end());
    vector<vector<int>> answersLeft = solve(ba, x);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r; l--,r--;
        int answer = (answersRight[l][r] - answersLeft[l][r]) % MOD;
        answer = (answer + MOD) % MOD;
        cout << answer << "\n";
    }
}

