#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>t;
     while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> x(n);
        int l=0,r=0;
        vector<int> seats(m+1,0);
        for(int i=0; i<n; i++){
            cin>>x[i];
            if(x[i]==-1)l++;
            else if(x[i]==-2)r++;
            else seats[--x[i]]++;
        }
        int ans = 0, cnt = 0;
        int pr=0,lr=0;
        for(int i=0; i<m; i++){
            if(seats[i])cnt++;
            else pr++;
        }
        ans=cnt+max(l,r);
        for(int i=0; i<m; i++){
            if(seats[i])ans = max(ans, cnt+min(l,lr)+min(r,pr));
            else lr++,pr--;
        }
        ans = min(ans,m);
        cout<<ans<<"\n";
     }
}