#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    int n;
    cin>>n;
    vector<string> x{"Beatrice","Belinda","Bella","Bessie","Betsy","Blue","Buttercup","Sue"};
    vector<pair<string,string>> res(n);
    for(int i=0; i<n; i++){
        cin>>res[i].first>>res[i].second>>res[i].second>>res[i].second>>res[i].second>>res[i].second;
    }
    do{
        bool done = true;
    for(auto[i,j]:res){
        int k = abs(find(x.begin(),x.end(),i)-find(x.begin(),x.end(),j));
        if(k!=1) done=false;
    }
    if(done)break;
    }while(next_permutation(x.begin(), x.end()));
    for(int i=0; i<8; i++){
        cout<<x[i]<<"\n";
    }
}