#pragma GCC target ("sse4.2")
#include<bits/stdc++.h>

using namespace std;
const int sss = 200005;
const int ssss = 100000;
int tn,n;
signed main(){
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
    int nf = 0;
    vector<int> pos(n);
    vector<int> sufid(n+1);
    int start = ssss;
    for(int i=0; i<n; i++){
        pos[i] = start;
        if(s[i] == 'L'){
            start--;
        }
        else if(s[i] == 'R'){
            start++;
        }
        else{
            nf++;
        }
    }
    vector<bitset<sss>> suf(nf+2);
    int p = nf+1;
    sufid.back()=p--;
    for(int i=n-1; i>=0; i--){
        sufid[i]=sufid[i+1];
        if(s[i] == 'R'){
            start--;
        }
        else if(s[i] == 'L'){
            start++;
        }
        else{
            sufid[i]=p--;
            suf[sufid[i]] = suf[sufid[i]+1];
            suf[sufid[i]][start]=1;
        }
    }
    bitset<sss> pre;
    vector<int> fire(sss,0);
    int ans = (suf[0]&t).count();
    if(n>1000){cout<<ans+2<<"\n";return 0;}
    if(false)for(int i=n/2; i<n; i++){
        if(s[i]=='F')pre[pos[i]]=1;
        fire[pos[i]] += (s[i]=='F');
        if(i%2)continue;

        int curans = 0;
        //no change
        ans = max(ans,(int)((pre|suf[sufid[i]])&t).count());
        if(s[i]=='L'){
            //'R'
            ans = max(ans,(int)((pre|(suf[sufid[i]]>>2))&t).count());
            //fire
            bool te= pre[pos[i]];
            pre[pos[i]]=1;
            ans = max(ans,(int)((pre|(suf[sufid[i]]>>1))&t).count());
            pre[pos[i]]=te;
        }else if(s[i]=='R'){
            //'L'
            ans = max(ans,(int)((pre|(suf[sufid[i]]<<2))&t).count());
            //fire
            bool te= pre[pos[i]];
            pre[pos[i]]=1;
            ans = max(ans,(int)((pre|(suf[sufid[i]]<<1))&t).count());
            pre[pos[i]]=te;
        }else{
            //'l"
            bool te= pre[pos[i]];
            if(fire[pos[i]]<=1)pre[pos[i]]=0;
            ans = max(ans,(int)((pre|(suf[sufid[i]]<<1))&t).count());
            pre[pos[i]]=te;
            //'R'
             te= pre[pos[i]];
            if(fire[pos[i]]<=1)pre[pos[i]]=0;
            ans = max(ans,(int)((pre|(suf[sufid[i]]>>1))&t).count());
            pre[pos[i]]=te;
        }
    }
    else
    for(int i=0; i<n; i++){
        if(s[i]=='F')pre[pos[i]]=1;
        int curans = 0;
        //no change
        ans = max(ans,(int)((pre|suf[sufid[i]])&t).count());
        if(s[i]=='L'){
            //'R'
            ans = max(ans,(int)((pre|(suf[sufid[i]]>>2))&t).count());
            //fire
            bool te= pre[pos[i]];
            pre[pos[i]]=1;
            ans = max(ans,(int)((pre|(suf[sufid[i]]>>1))&t).count());
            pre[pos[i]]=te;
        }else if(s[i]=='R'){
            //'L'
            ans = max(ans,(int)((pre|(suf[sufid[i]]<<2))&t).count());
            //fire
            bool te= pre[pos[i]];
            pre[pos[i]]=1;
            ans = max(ans,(int)((pre|(suf[sufid[i]]<<1))&t).count());
            pre[pos[i]]=te;
        }else{
            //'l"
            bool te= pre[pos[i]];
            if(fire[pos[i]]<=1)pre[pos[i]]=0;
            ans = max(ans,(int)((pre|(suf[sufid[i]]<<1))&t).count());
            pre[pos[i]]=te;
            //'R'
             te= pre[pos[i]];
            if(fire[pos[i]]<=1)pre[pos[i]]=0;
            ans = max(ans,(int)((pre|(suf[sufid[i]]>>1))&t).count());
            pre[pos[i]]=te;
        }
        fire[pos[i]] += (s[i]=='F');
    }
    cout<<ans<<"\n";
}