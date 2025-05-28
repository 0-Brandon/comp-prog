#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int acc=0;
    vector<int> ans(n);
    vector<double> x(n);
    vector<bool> isint(n,false);
    for(int i=0;i<n; i++){
        cin>>x[i];
        ans[i]=ceil(x[i]);
        if(ans[i]==x[i])isint[i]=true;
        acc+=ans[i];
    }
    int idx = -1;
    while(acc>0){
        idx++;
        if(isint[idx])continue;
        ans[idx]--;
        acc--;
    }
    for(auto& i:ans)cout<<i<<"\n";
}