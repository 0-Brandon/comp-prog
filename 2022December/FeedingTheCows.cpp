#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<int> x(n);
        for(int i=0; i<n; i++){
            x[i]=s[i];
        }
        int nextg=-10e7, nexth=-10e7;
        vector<char> ret(n, '.');
        int ans = 0;
        for(int i=0; i<n; i++){
            if(x[i]=='G'){
                if(abs(i-nextg)>m){
                    if(i+m<n)
                    ret[i+m]= 'G';
                    else{
                        for(int j=min(i+m-1,n-1); j>=i-m; j--){
                            if(ret[j]=='.') {
                            ret[j]='G';
                            nextg=j;
                            break;
                            }
                        }
                    }
                    ans++;
                    if(i+m<n)nextg=i+m;
                }
            }
            else{
                if(abs(i-nexth)>m){
                    if(i+m<n)
                    ret[i+m]='H';
                    else{
                        for(int j=min(i+m-1,n-1); j>=i-m; j--){
                            if(ret[j]=='.') {
                            ret[j]='H';
                            nexth=j;
                            break;
                            }
                        }
                    }
                    ans++;
                    if(i+m<n)nexth=i+m;
                }
            }
        }
        cout<<ans<<"\n";
        for(auto& i:ret){
            cout<<i;
        }
        cout<<"\n";
    }
}