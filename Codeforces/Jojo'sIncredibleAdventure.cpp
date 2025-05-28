#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool flag = false;
        for(auto& i:s)if(i!='1')flag=true;
        if(!flag){
            cout<<1LL*s.size()*s.size()<<"\n";
            continue;
        }
        s=s+s;
        long long int ans = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0')continue;
            long long int cnt = 0;
            while(s[i]=='1')cnt++,i++;
            ans = max(ans,cnt);
        }
        cout<<((ans+1)/2)*((ans+2)/2)<<"\n";
    }
}