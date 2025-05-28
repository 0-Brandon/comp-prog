#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> x(12);
    for(int i=0; i<12; i++){
        cin>>x[i];
    }
    sort(x.begin(), x.end());
    vector<int> ts(4);
    int i=0;
    int ans = INT_MAX;
    do{
         ts[0]=accumulate(x.begin(), x.begin()+3,0);
         ts[1]=accumulate(x.begin()+3, x.begin()+6,0);
         ts[2]=accumulate(x.begin()+6, x.begin()+9,0);
         ts[3]=accumulate(x.begin()+9, x.begin()+12,0);
         ans = min(ans, *max_element(ts.begin(), ts.end())-*min_element(ts.begin(), ts.end()));
    }while(next_permutation(x.begin(), x.end()));
    cout<<ans;
}