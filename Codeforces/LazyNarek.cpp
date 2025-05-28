#include <bits/stdc++.h>
#define int long long
using namespace std;

string str = "narek";
map<char,char> mp = {{'n','k'},{'k','e'},{'e','r'},{'r','a'},{'a','n'}};
void solve(){
    int n, m;cin>>n>>m;
    vector x(n,vector<int>(5));//first letter n,a,r,e,k;
    vector last(n, vector<char>(5));//last letter if we start on i
    for(int i=0; i<n; i++){
        string s;cin>>s;
        for(int id = 0; id<5; id++){
            bool b = false;
            int ans = 0; //scoren-scorec
            int cur = id;
            for(int j=0; j<m; j++){
                if(s[j] =='n'||s[j]=='a'||s[j]=='r'||s[j]=='e'||
                s[j]=='k'){
                    ans--;
                }
                if(s[j] == str[cur]){
                    b=true;
                    last[i][id] = s[j];
                    if(str[cur] =='k')ans+=10;
                    cur = (cur+1)%5;
                }
            }
            x[i][id] = ans;
            if(!b)x[i][id]=INT_MIN;
        }
    }
    map<char,int> ma; //max ending on a certain letter
    for(auto& i:str)ma[i]=INT_MIN;
    ma['k']=0;
    int ans = 0;
    for(int i=0; i<n; i++){
        map<char,int> nma=ma;
        for(int id = 0; id<5; id++){
            //our first letter is id, their last letter is mp[id];
            nma[last[i][id]] = max({nma[last[i][id]],ma[last[i][id]],ma[mp[str[id]]]+x[i][id]});
            ans = max(ans,nma[last[i][id]]);
        }
        swap(nma,ma);
      //  for(auto& i:ma)cout<<i.second<<" ";cout<<"\n";
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            //cout<<x[i][j]<<" "; 
        }
      //  cout<<"\n";
    }
    cout<<ans<<"\n";
}
signed main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;cin>>t;
    while(t--)solve();
}