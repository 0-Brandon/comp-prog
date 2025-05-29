#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> p(n+1,-1);
    int acc = 0;
    vector<int> inv(n+1);
    for(int i=2; i<=n; i++){
        cout<<"? 1 "<<i<<"\n";
        int a;
        cin>>a;
        inv[i] = a-acc;
        acc+=inv[i];
    }
    
    for(int i=n; i>=1; i--){
        int cnt = 0;
        int j=n;
        for(; cnt<inv[i]; j--){
            if(p[j]==-1)cnt++;
        }
        while(p[j]!=-1)j--;
        p[j] = i;
    }
    vector<int> d(n+2,1e9);
    d[0] = -1e9;
    for (int i=1;i<=n;i++) {
        int l = upper_bound(d.begin(),d.end(),p[i])-d.begin();
        if (d[l-1]<p[i]&&p[i]<d[l])
            d[l] = p[i];
    }
    int ans = 0;
    for (int l=0; l<=n; l++) {
        if (d[l]<1e9)
            ans = l;
    }
    cout<<"! "<<ans;
}