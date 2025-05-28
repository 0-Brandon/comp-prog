#include <bits/stdc++.h>

using namespace std;
int c;
bool check(int i, vector<int>& x, vector<int>& chord){
    vector<int> sub(x.begin()+i, x.begin()+i+c);
    sort(sub.begin(), sub.end());
    vector<int> sub1(c);
    for(int j=1; j<c; j++){
        sub1[j]=sub[j]-sub[j-1];
    }
    sub1[0]=0;
    for(int j=0; j<c; j++){
        cout<<chord[j]<<" "<<sub1[j]<<"\n";
        if(chord[j]!=sub1[j]) return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
    }
    cin>>c;
    vector<int> chord1(c);
    for(int i=0; i<c; i++){
        cin>>chord1[i];
    }
    sort(chord1.begin(), chord1.end());
    vector<int> chord(c);
    for(int i=1; i<c; i++){
        chord[i]=chord1[i]-chord1[i-1];
    }
    chord[0]=0;
    int ans = 0;
    vector<int> l;
    for(int i=0; i<=n-c; i++){
        if(check(i,x,chord)){
            ans++;
            l.push_back(i);
        }
    }
    cout<<ans<<"\n";
    for(auto i:l){
        cout<<i+1<<"\n";
    }
}