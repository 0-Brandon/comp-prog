#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int l=0, r=n-1;
        bool once = false, twice = false,  thrice = false;
        while(l<=r){
            if(s[l]==s[r]&&once){
                twice = true;
            }
            if(s[l]!=s[r]&&twice){
                thrice = true;
                break;
            }
            if(s[l]!=s[r]){
                once = true;
            }
            r--;l++;
        }
        if(thrice){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
    }
}