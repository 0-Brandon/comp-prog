#include <bits/stdc++.h>

using  namespace std;

map<char,int> mp {{'A',0},{'B',1},{'C',2},{'D',3}};
void solve(){
    cin.tie(0)->sync_with_stdio(false);
    int n;cin>>n;
    vector<int> x(n);
    vector<int> score(n);
    for(int i=0; i<n; i++){
        string s;cin>>s;
        for(int j=18; j>=0; j-=2){
            x[i]|=(mp[s[(18-j)/2]]<<j);
        }
        cin>>score[i];
    }
    for(int i=0; i<1<<20; i++){
        bool ok = true;
        for(int j=0; j<n; j++){
            int num = (~(x[j]^i))&((1<<20)-1);
            int c = 0;
            for(int k=0; k<20;k+=2){
                if(((num>>k)&(3))==3){
                    c++;
                }
            }
            if(c*10!=score[j]){ok = false;break;}
        }
        ans+=ok;
    }
    cout<<ans<<"\n";
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}