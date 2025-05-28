#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s=="^"){
            cout<<1<<"\n";
            continue;
        }
        int cnt =0;
        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='_'&&s[i+1]=='_')cnt++;
        }
        if(s[0]=='_')cnt++;
        if(s.back()=='_')cnt++;
        cout<<cnt<<"\n";
    }
}