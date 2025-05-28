#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N, D, A, B;
    cin >> N >> D >> A >> B;
    vector<ll> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    // Step 1: Sort descending
    sort(b.begin(), b.end(), greater<ll>());
    // Step 2: Compute net changes
    ll k = A - B;
    ll p = (D * k) / N; // Full periods
    ll total_ops = p * N / k;
    ll r = D - total_ops; // Remaining operations
    ll extra = r * k; // Elements getting +1 more
    // Step 3: Compute final array and sum of squares
    ll sum_squares = 0;
    for (int i = 0; i < N; i++) {
        ll final_val = b[i] + p + (i < extra ? 1 : 0);
        sum_squares += final_val * final_val;
    }
    cout << sum_squares << "\n";
    return 0;
}