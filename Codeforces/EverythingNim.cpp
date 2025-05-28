#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    set<int> x;
    for(int i=0; i<n; i++){
        int a;cin>>a;
        x.insert(a);
    }
    int c=0;
    int l = 0;
    for(auto& i:x){
        if(i-l==1){
            l=i;c++;
        }
        else{
            break;
        }
    }
    if(c==x.size()&&x.size()%2==0)cout<<"Bob";
    else if(c==x.size()&&x.size()%2!=0)cout<<"Alice";
    else if(c%2==0)cout<<"Alice";
    else cout<<"Bob";
    cout<<"\n";
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}