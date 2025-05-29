/*[a,b] to [i,j]

i>=a
every subarray
j>=i
b>=i

every subarray starting from a+1 to i-1 is taken calcualted very fast precalculated
x x x x x
the end points subarray from a,b to a,n can also be calculated fast?
suffix*num - pyramid sum up to index
for i,j, add pyramid sum 

binary search on left endpoint
find index
binary serach on right endpoint
find index
find sum of a+1 to i-1
find endpoint sums
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<int> pref(n+2);
    vector<int> p(n+1);
    vector<int> pp(n+1);
    //0
    //0 0
    //0 0 0
    //0 0 0 0 
    //0 0 0 0 0
    //0 1 2 3 4
    for(int i=0; i<n; i++){
        pref[i+1] = pref[i]+x[i];
    }
    for(int i=n-1; i>=0; i--){
        p[i] = p[i+1]+(n-i)*x[i];
    }
    for(int i=0; i<n; i++){
        pp[i+1] = pp[i]+p[i];
    }
    auto search = [&](int i)->pair<int,int> {
        int l = 0, h = n-1;
        while(l<h){
            int mid =l+(h-l+1)/2;
            if(n*(n+1)/2-(n-mid)*(n-mid+1)/2<=i){
                l = mid;
            }
            else{
                h = mid-1;
            }
        }
        return {l, l+i-(n*(n+1)/2-(n-l)*((n-l)+1)/2)};
    };
    int q; cin>>q;
    while(q--){
        int l, r;cin>>l>>r;
        //do we need to do l--,r-- here?
        l--,r--;
        auto[a,b] = search(l);
        auto[i,j] = search(r);
       // cout<<a<<" "<<b<<" "<<i<<" "<<j<<" ";
        //pyramid sum of a+1 to i-1
        int ans = pp[i]-pp[a+1];
        //cout<<pp[i]-pp[a+1]<<"\n";
        //sum of a,b to a,n
        //pyramid b + (n-b)*(pref[b]-pref[a-1]);
        ans += p[b] + (n-b)*(pref[b]-pref[a]);
       // cout<<p[b] + (n-b)*(pref[b]-pref[a])<<"\n";
        //sum of i,i to i,j
        //1 2 5 10
        //0 1 3 8 18
        //0
        //0 0
        //0 0 0
        //0 0 0 0
        //p[i] - p[j+1] - (j-i+1)*(pref[j+1]-pref[i])
        //10-0-(3-3)*
        ans += p[i]-p[j+1]-(n-1-j)*(pref[j+1]-pref[i]);
        //cout<<p[i]-p[j+1]-(n-1-j)*(pref[j+1]-pref[i])<<"\n";
        cout<<ans<<"\n";
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t=1;
    while(t--){
        solve();
    }
}