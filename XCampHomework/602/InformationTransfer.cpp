#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    vector<int> ind(n);
    for(int i=0; i<n; i++){
        cin>>x[i];x[i]--;
        ind[x[i]]++;
    }
    int ans = INT_MAX;
    vector<bool> vis(n);
    auto find = [&](int s){
        int a = x[s], b = x[x[s]];
        set<int> nodes;
        nodes.insert(s);
        bool f = false;
        while(a!=b){
            a=x[a],b=x[x[b]];
            if(vis[a]||vis[b]){
                f=true;
                break;
            }
            nodes.insert(a);
            nodes.insert(b);
        }
        if(f){
            for(auto& i:nodes)vis[i] = true;
            return;
        }
        a = s;
        while(a!=b){
            a=x[a],b=x[b];
            nodes.insert(a);
            nodes.insert(b);
        }
        for(auto& i:nodes)vis[i] = true;
        int l =1;
        b=x[a];
        while(a!=b)b = x[b], l++;
        ans = min(ans,l);
    };
    for(int i=0; i<n; i++){
        if(!vis[i]){
            find(i);
        }
    }
    cout<<ans<<"\n";
}