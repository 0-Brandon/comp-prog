#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;cin>>n;
    vector<int> par(n);
    par[1] = 0;
    vector<int> time;
    int i;
    for(i=2; i<n; i++){
        cout<<"? 1 "<<i<<endl;
        int r;cin>>r;
        if(r) {
            time.push_back(i);
            par[i] = 0;
        }
        else{
            time.push_back(i);
            par[i] = 1;
            break;
        }
    }
    //i is child of 1
    //time.back is child of 1
    int p = 0;
    map<int,vector<int>> mp;
    for(int j=i+1; j<n; j++){
        int r;
        if(p==time.size()-1){
            for(;j<n; j++){
                par[j] = time[p];
                p++;
                time.push_back(j);
            }
            break;
        }
        do{
            cout<<"? "<<j<<" "<<time[p]<<endl;
            cin>>r;
            if(r==0){par[j] = time[p]; time.push_back(j); p++;}
            else if (p+1==time.size()-1){p++;break;}
            else p++;
        }while(r);
        if(p==time.size()-1){
            for(;j<n; j++){
                par[j] = time[p];
                p++;
                time.push_back(j);
            }
            break;
        }
    }
    cout<<"! ";
    for(int i=1; i<n; i++)cout<<par[i]<<" ";cout<<endl;
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)solve();
}

