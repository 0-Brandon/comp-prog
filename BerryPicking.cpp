#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("berries.in","r",stdin);
    freopen("berries.out","w",stdout);
    int n, k;
    cin>>n>>k;
    vector<int> x(n);
    int maxb=0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        maxb=max(maxb,x[i]);
    }
    int ans = 0;
    for(int b=1; b<=maxb; b++){
        
        int cur = 0;
        sort(x.begin(),x.end(),greater<int>());
        int numk=0;
        for(int j=0; j<n; j++){
            numk+=x[j]/b;
        }
        if(numk>=k){
            ans = max(ans,(k/2)*b);
            continue;
        }
        sort(x.begin(),x.end(),[&](int& i, int& j){return i%b>j%b;}); 
        int curcount = 0;
        if(numk>k/2){
            cur+=(numk-k/2)*b;
            curcount+=numk-k/2;
        }
        int j=0;
        if(numk<k/2)j+=k/2-numk;
        while(curcount<k/2){
            cur+=x[j]%b;
            curcount++;
            j++;
        }
        ans = max(ans,cur);
    }
    cout<<ans;
}