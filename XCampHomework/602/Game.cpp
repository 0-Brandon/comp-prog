#include <bits/stdc++.h>

using namespace std;
int main() {
   cin.tie(0)->sync_with_stdio(false);
   int n, m;
	cin>>n>>m;
    vector<int> rmax(257,-1);
    vector<int> a(n);
    vector<int> dp(257);
	for(int i=0; i<n; i++) {
		cin>>a[i];
		rmax[a[i]]=i;
	}
    auto work = [&](){
        dp.assign(257,1);
        vector<int> v;
        for(int i=0; i<256; i++) {
            if(rmax[i]!=-1) {
                v.push_back(i);
            }
        }
        sort(v.begin(), v.end(), [&](int i, int j){return rmax[i]>rmax[j];});
        for(auto& i:v){
            bool ok = false;
            for(int j=0; j<8; j++){
                int tmp = i^(1<<j);
                if(rmax[tmp]<rmax[i])continue;
                ok|=!dp[tmp];
            }
            dp[i] = ok;
        }
    };
	work();
	for(int i=0; i<m; i++) {
		int op, k;
		cin>>op>>k;
		if(op==1){
			rmax[k] = n;
			n++;
            a.push_back(k);
			work();
		}
        else{
            k--;
            if(rmax[a[k]]>k)cout<<"Alice";
            else if(dp[a[k]])cout<<"Alice";
            else cout<<"Bob";
            cout<<"\n";
		}
	}
}