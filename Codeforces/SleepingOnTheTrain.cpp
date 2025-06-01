#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, t, a, b;
    cin>>n>>t>>a>>b;
    vector<int> x(t);
    int last = a;
    int dir = 1;
    int cnt = 0;
    //1 means x[i]should be > cnt, 0 means x[i] should be <cnt
    for(int i=0; i<t; i++){
        cin>>x[i];
        if(i==0&&x[i]==a)last = a;
        if(dir==1&&x[i]>=last||dir==0&&x[i]<=last){
            last = x[i];
            continue;
        }
        cnt++,dir^=1,last = x[i];
    }
    if(dir==1&&b<=last||dir==0&&b>last)cnt++;
    last = a, dir = 0;
    int cnt2 = 0;
     for(int i=0; i<t; i++){
        if(i==0&&x[i]==a)last = a-1;
        if(dir==1&&x[i]>=last||dir==0&&x[i]<=last){
            last = x[i];
            continue;
        }
        cnt2++,dir^=1,last = x[i];
    }
    if(dir==1&&b<=last||dir==0&&b>last)cnt2++;
    cout<<min(cnt2,cnt)<<" ";
}