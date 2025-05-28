#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
bool ok(int i, int p){
    return (n*(n+1))/2-(n-i-1)*(n-i)/2<p;
}
void solve(){
    string s;
    cin>>s;
    n=s.size();
    vector<int> rem(n,-1);
    int c = 0;
    stack<int> x;
    for(int i=0; i<n; i++){
        while(!x.empty()&&s[x.top()]>s[i]){
            rem[x.top()] = c++;
            x.pop();
        }
        x.push(i);
    }
    for(int i=n-1; i>=0; i--){
        if(rem[i]==-1)rem[i]=c++;
    }
    int pos;
    cin>>pos;
    int l = -1, h = n;
    while(l<h){
        int mid = (l)+(h-l+1)/2;
        if(ok(mid,pos)){
            l = mid;
        }
        else{
            h = mid-1;
        }
    }
    int cnt = 0;
    int id = pos-((n*(n+1))/2-(n-l-1)*(n-l)/2);
    for(int i=0; i<n; i++){
        if(rem[i]>l)cnt++;
        if(cnt==id){
            cout<<s[i];
            break;
        }
    }
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}