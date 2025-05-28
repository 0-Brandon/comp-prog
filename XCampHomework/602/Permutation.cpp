#include <bits/stdc++.h>
using namespace std;
int id = 0;
vector<int> f(long long k){
    vector<int> ans;
    if(k<=4){
        for(int i=1; i<k; i++)ans.push_back(id++);
        reverse(ans.begin(),ans.end());
    }
    else if(k%2==0){
        ans = f(k/2);
        ans.push_back(id++);
    }
    else if(k%4==1){
        ans = f(k-1);
        ans.insert(ans.begin(), id++);
    }
    else{
        ans = f(k-3);
        ans.insert(ans.begin()+2,id++);
    }
    return ans;
}
vector<int> construct_permutation(long long k){
    id = 0;
    return f(k);
}
/*
signed main(){
    for(int j=1; j<10; j++){
    vector<int> ans = construct_permutation(j);
    for(auto& i:ans)cout<<i<<" ";cout<<"\n";
    }
}
*/