#include <bits/stdc++.h>
using namespace std;
 

struct BIT {
    int n;
    vector<int> e;
    BIT(int n) : n(n), e(n+1,0) {}
    void update(int i, int delta) {
        for(; i<=n; i += i&-i)
            e[i] += delta;
    }
    int query(int i) {
        int s = 0;
        for(; i; i -= i&-i)
            s += e[i];
        return s;
    }
};
 
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, p;
    cin>>n>>p;
    vector<long long> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if(p == 1){
        int N = n;
        vector<long long> lv(n), rv(n);
        for (int i = 0; i < n; i++){
            lv[i] = a[i] - (i+1);
            rv[i] = a[i] + (i+1);
        }
        vector<long long> cl = lv;
        sort(cl.begin(), cl.end());
        cl.erase(unique(cl.begin(), cl.end()), cl.end());
        vector<long long> cr = rv;
        sort(cr.begin(), cr.end());
        cr.erase(unique(cr.begin(), cr.end()), cr.end());
        vector<int> lcnt(n, 0);
        BIT bitl(cl.size());
        for (int i = 0; i < n; i++){
            int pos = upper_bound(cl.begin(), cl.end(), lv[i]) - cl.begin();
            int cnt = bitl.query(pos-1);
            lcnt[i] = cnt;
            bitl.update(pos, 1);
        }
        vector<int> rcnt(n, 0);
        BIT bitr(cr.size());
        for (int i = n - 1; i >= 0; i--){
            int pos = upper_bound(cr.begin(), cr.end(), rv[i]) - cr.begin();
            int cnt = bitr.query(pos-1);
            rcnt[i] = cnt;
            bitr.update(pos, 1);
        }
        for (int i = 0; i < n; i++){
            cout <<1+lcnt[i]+rcnt[i]<<"\n";
        }
    }else{
        vector<long long> sorted = a;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < n; i++){
            int rank = upper_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin();
            cout <<rank<<"\n";
        }
    }
}
