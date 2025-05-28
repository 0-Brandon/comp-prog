#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n),b(n);
    vector<priority_queue<int,vector<int>,greater<int>>> mis(2);
    string s1, s2;cin>>s1>>s2;
    int p = 0;
    int ans= 0;
    for(int i=0; i<n; i++){
        a[i]=s1[i]-'0';
        b[i]=s2[i]-'0';
    }
    int id0=0, id1=1;
    for(int i=0; i<n; i++){
        while(p+1<n&&p-i<k){
            p++;
            if(a[p]!=b[p]){
                mis[b[p]].push(p);
            }
        }
        while(id0<n&&(id0<=i||(a[id0]==1)||(id0<p&&a[id0]==0&&b[id0]==1)))id0++;
        while(id1<n&&(id1<=i||(a[id1]==0)||(id1<p&&a[id1]==1&&b[id1]==0)))id1++;
        for(int j=0; j<2; j++){
            while(!mis[j].empty()&&mis[j].top()<=i)
                mis[j].pop();
        }
        if(a[i]!=b[i]){
            //mis[0] and mis[1] hold the indices of indices that don't match
            //wher b[i] is 0 or b[i] is 1
            if(!mis[a[i]].empty()){
                int id = mis[a[i]].top(); //we find index that fixes both
                mis[a[i]].pop();
                swap(a[i],a[id]);
                ans++;
            }
            //no index in range, we are forced to make multiple swaps
            else{
                if(a[i]==0){
                    //we need closest 1
                    ans+=(id1-i+k-1)/k;
                    swap(a[i],a[id1]);
                    if(b[id1]!=a[id1]&&id1<p)mis[b[id1]].push(id1);
                }
                else if(a[i]==1){
                    //we need closest 0 
                    ans+=(id0 -i+k-1)/k;
                    swap(a[i],a[id0]);
                    if(b[id0]!=a[id0]&&id0<p)mis[b[id0]].push(id0);
                }
            }
        }
    }
    cout<<ans<<"\n";
}

//x[i]!=y[i]
//if some index in range i, i+k j such that x[j]!=y[j] and x[i]==y[j]
//we swap with earliest j
//else, we swap with latest index