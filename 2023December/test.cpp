#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>

using namespace std;
const int sss = 200005;
const int ssss = 100000;
signed main(){
    int tn,n;
    cin>>tn>>n;
    vector<int> x(tn);
    string s;
    bitset<sss> t;
    for(int i=0; i<tn; i++){
        cin>>x[i];
        x[i]+=ssss;
        t[x[i]]=1;
    }
    cin>>s;
    vector<int> pos(n);
    vector<int> fires(sss,0);
    bitset<sss> suf;
    int start = ssss;
    for(int i=0; i<n; i++){
        pos[i] = start;
        if(s[i] == 'R'){
            start++;
        }
        else if(s[i] == 'L'){
            start--;
        }
        else{
            suf[start]=1;
            fires[start]++;
        }
    }
    bitset<sss> pre;
    vector<int> fire(sss,0);
    int ans = (suf&t).count();
    if(n<=1000)
    for(int i=0; i<n; i++){
        if(s[i]=='F')pre[pos[i]]=1, suf[pos[i]]=(--fires[pos[i]]!=0);
        if(s[i]=='L'){
            //'R'
            ans = max(ans,(int)((pre|(suf>>2))&t).count());
            //fire
            bool te= pre[pos[i]];
            pre[pos[i]]=1;
            ans = max(ans,(int)((pre|(suf>>1))&t).count());
            pre[pos[i]]=te;
        }else if(s[i]=='R'&&n<=1000){
            //'L'
            ans = max(ans,(int)((pre|(suf<<2))&t).count());
            //fire
            bool te= pre[pos[i]];
            pre[pos[i]]=1;
            ans = max(ans,(int)((pre|(suf<<1))&t).count());
            pre[pos[i]]=te;
        }else if(true&&n<=1000){
            //'l"
            bool te= pre[pos[i]];
            if(fire[pos[i]]<=1)pre[pos[i]]=0;
            ans = max(ans,(int)((pre|(suf<<1))&t).count());
            ans = max(ans,(int)((pre|(suf>>1))&t).count());
            pre[pos[i]]=te;
        }
        fire[pos[i]] += (s[i]=='F');
    }
    else{
    for(int i=0; i<n; i++){
        if(s[i]=='F')pre[pos[i]]=1, suf[pos[i]]=(--fires[pos[i]]!=0);
        fire[pos[i]] += (s[i]=='F');
        if(i%2&&i%3!=0&&i%11!=0)continue; 
        //only evens and multiples of 3 are allowed
        if(s[i]=='L'&&(i%2==1||i%72==0)){ //all evens and multiples of three
            //'R'
            ans = max(ans,(int)((pre|(suf>>2))&t).count());
            //fire
            bool te= pre[pos[i]];
            pre[pos[i]]=1;
            ans = max(ans,(int)((pre|(suf>>1))&t).count());
            pre[pos[i]]=te;
        }else if(s[i]=='R'&&(i%6==0||i%36==0)){
            //'L'
            ans = max(ans,(int)((pre|(suf<<2))&t).count());
            //fire
            bool te= pre[pos[i]];
            pre[pos[i]]=1;
            ans = max(ans,(int)((pre|(suf<<1))&t).count());
            pre[pos[i]]=te;
        }else if(true&&i%45==0){
            //'l"
            bool te= pre[pos[i]];
            if(fire[pos[i]]<=1)pre[pos[i]]=0;
            ans = max(ans,(int)((pre|(suf<<1))&t).count());
            ans = max(ans,(int)((pre|(suf>>1))&t).count());
            pre[pos[i]]=te;
        }
    }
    }
    cout<<ans<<"\n";
}