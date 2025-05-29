#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = 0;
    auto has = [&](int i, int d){
        while(i){if(i%10==d)return true;else i/=10;}
        return false;
    };
    for(int i=0; i<n; i++){
        int dig = s[i]-'0';
        while(!has(ans,dig))ans++;
        int t = ans;
        int m = 1;
        while(t!=1&&t!=0)t/=10,m*=10;
        t = ans;
        while(m!=1&&m!=0){
            if(t%m/(m/10)==s[i]-'0')i++;
            m/=10;
        }
        cout<<"\n";
        i--;
    }
    cout<<ans<<"\n";
}