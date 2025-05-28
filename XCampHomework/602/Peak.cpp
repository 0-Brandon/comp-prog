#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define int long long
using namespace __gnu_pbds;
using namespace std;
typedef tree<
int,
null_type,
greater<int>,
rb_tree_tag,
tree_order_statistics_node_update>
os;

signed main(){
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> t;
    for(int i=0; i<n; i++){
        cin>>x[i];t.push_back(x[i]);
    }
    sort(t.begin(),t.end());
    for(int i=0; i<n; i++)x[i] = lower_bound(t.begin(),t.end(),x[i])-t.begin();
    os s;
    int suf = 0;
    vector<int> ss(n);
    for(int j=n-1; j>=0; j--){
        suf+= ss[j]=s.order_of_key(x[j]);
        s.insert(x[j]);
    }
    int pre =0;
    os se;
    int ans = n*n*5;
    for(int i=0; i<n; i++){
        ans = min(ans,pre+suf);
        pre+=se.order_of_key(x[i]);
        suf-=ss[i];
        se.insert(x[i]);
    }
    cout<<ans<<"\n";
}