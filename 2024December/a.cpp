#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> pre,nxt;
int gpre(int i){
 return pre[i] ==-1?i:pre[i] = gpre(pre[i]); 
}
int gnxt(int i){
    return nxt[i]==-1?i:nxt[i] = gnxt(nxt[i]); 
}
signed main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    vector<int> last(n+1,-1);
    vector<int> right(n,-1);
    vector<int> left(n,-1);
    for(int i=0; i<n; i++){
        left[i] = last[x[i]];
        last[x[i]] = i;
    }
    last.assign(n+1,-1);
    for(int i=n-1; i>=0; i--){
        right[i] = last[x[i]];
        last[x[i]] = i;
    }
    pre.resize(n,-1),nxt.resize(n,-1);
    vector<set<int>> s(n+1);
    for(int i=0; i<n; i++){
        if(right[i]!=-1)s[right[i]-i].insert(i);
    }
    int cc = n;
    vector<int> ans;
    for(int d=1; d<=n; d++){
        for(auto& i:s[d]){
            cc--;
            //remove the two neighboring ones
            if(left[gpre(i)]!=-1)s[gnxt(i)-gpre(left[gpre(i)])].erase(gpre(left[gpre(i)])); //do we need to go gpre[i] or can we just do pre[i][j]
            if(right[gnxt(i)]!=-1&&right[gnxt(right[gnxt(i)])]!=-1)s[gnxt(right[gnxt(right[gnxt(i)])])-right[gnxt(i)]].erase(right[gnxt(i)]);
            //link the two components
            pre[right[gnxt(i)]] = gnxt(i);
            nxt[gnxt(i)] = right[gnxt(i)];
            //add the two new ones
            if(left[gpre(i)]!=-1)s[gnxt(i)-gpre(left[gpre(i)])].insert(gpre(left[gpre(i)]));
            if(right[gnxt(i)]!=-1)s[gnxt(right[gnxt(i)])-gpre(i)].insert(gpre(i));
        }
        ans.push_back(cc);
    }
    for(auto& i:ans)cout<<i<<" ";
}


for(int j=0; j<pos[i].size(); j++){
    ans[pos[i][j+1]-pos[i][j]]--;
    
}