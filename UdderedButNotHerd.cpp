#include <bits/stdc++.h>

using namespace std;

int main(){
    string a;
    cin>>a;
    string h;
    cin>>h;
    int count= 0;
    int ans = 1;
    int done = false;
    while(count!=h.size()){
        for(int i=0; i<26; i++){
            if(h[count]==a[i]){
                count++;
                if(count==h.size()){
                    done= true;
                }
            }
        }
        if(done) break;
        ans++;
    }
    cout<<ans;
}