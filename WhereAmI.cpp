#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("whereami.in","r",stdin);
    freopen("whereami.out","w",stdout);
   int n;
   cin>>n;
   vector<int> x(n);
   string s;
   cin>>s;
   bool done = true;
   for(int i=1; i<=n; i++){
    done = true;
    for(int j=0; j<=n-i; j++){
        string sub = s.substr(j,i);
        for(int k=0; k<j; k++){
            if(s.substr(k,i)==sub){
                done = false;
            }
        }
        
    }
    if(done){
        cout<<i;
        break;
    }
   }
}