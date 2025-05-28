#include <bits/stdc++.h>
#define int long long
using namespace std;

struct BIT {
    vector<int> e;
    int n;
    BIT(int a) : n(a + 1), e(a + 2, 0) {}
    void update(int idx, int value) {
        idx++;
        for (; idx <= n; idx += idx & -idx) {
            if (value > e[idx]) {
                e[idx] = value;
            } else {
                break;
            }
        }
    }
    int query(int idx) {
        idx++;
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) {
            res = max(res,e[idx]);
        }
        return res;
    }
};
vector<int> work(vector<int>& t) {
    int n = t.size();
    vector<int> s(t);
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    int m = s.size();
    BIT  b(m);
    vector<int> ll(n, 1);
    for (int i=0; i<n; i++) {
        int cur = t[i];
        int idx = lower_bound(s.begin(), s.end(), cur) - s.begin();
        int qidx = idx - 1;
        int ma = 0;
        if (qidx>=0) {
            ma = b.query(qidx);
        }
        ll[i] = ma + 1;
        int uidx = lower_bound(s.begin(), s.end(), cur) - s.begin();
        if (uidx < m && s[uidx] == cur) {
            b.update(uidx, ll[i]);
        } else {
            b.update(uidx, ll[i]);
        }
    }
    return ll;
}
vector<int> krow(const vector<int>& t) {
    int n = t.size();
    vector<int> r(t.rbegin(), t.rend());
    vector<int> ans = work(r);
    reverse(ans.begin(), ans.end());
    return ans;
}
signed main() {
    cin.tie(0)->sync_with_stdio(false);
    int n,x;cin>>n>>x;
    vector<int> t(n);
    for(int i=0; i<n; i++)cin>>t[i];
    vector<int> ll = work(t);
    vector<int> rl = krow(t);
    int og = *max_element(ll.begin(), ll.end());
    int ans = og;
    for(int i=0; i<n; i++){
        int l = -x+1;
        if (i>0) {
            l = max(l,t[i-1]- t[i]+1);
        }
        int h = x-1;
        if (i<n-1) {
            h = min(h,t[i+1]-t[i]-1);
        }
        if (l>h) continue;
        int c=(i>0?ll[i-1]:0)+1+(i<n-1?rl[i+1]:0);
        ans = max(ans,c);
    }
    vector<pair<int, int>> intervals;
    int start = 0;
    intervals.emplace_back(start, start);
    for (int i=1;i<n;i++) {
        if (t[i]>t[i-1]) {
            intervals.back().second = i;
        } else {
            start = i;
            intervals.emplace_back(start, i);
        }
    }
    for (auto& i : intervals) {
        int l = i.first;
        int r = i.second;
        int lower = -x+1;
        if (l>0){
            lower = max(lower,t[l-1]-t[l]+1);
        }
        int upper = x - 1;
        if (r<n-1) {
            upper = min(upper,t[r+1]-t[r]-1);
        }
        if(lower>upper)continue;
        int c = (l>0?ll[l-1]:0)+(r-l+1)+(r<n-1?rl[r+1]:0);
        if (c>ans){
            ans = c;
        }
    }
    cout<<ans<<"\n";
}