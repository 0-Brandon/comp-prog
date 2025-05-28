#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(n%k!=0){cout<<"-1\n";return;}
    map<char,int> cnt;
    int b=0;
    for(int i=0; i<n; i++){
        cnt[s[i]]++;
    }
    for(auto& [l,c]:cnt)b+=(k-c%k)%k;if(b==0){cout<<s<<"\n";return;}
    for(int i=n-1; i>=0; i--){
        cnt[s[i]]--;
        for(int j=s[i]+1; j<='z'; j++){
            cnt[j]++;
            int su = 0;
            for(auto& [pl,l]:cnt)su+=( k - l % k ) % k;
            if(su<=n-1-i){
                cout<<s.substr(0,i);
                cout<<(char)j;
                string add = "";
                for(auto& [l,c]:cnt){
                    add+=string(( k - c % k ) % k,l);
                }
                while(add.size()+i+1<n)add+='a';
                sort(add.begin(),add.end());
                cout<<add<<"\n";
                return;
            }
            cnt[j]--;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}