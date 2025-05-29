#include <bits/stdc++.h>
using namespace std;


int main(){
    string st;
    int n;
	cin >> n >> st;
    vector<int> a(n+1),l(n+1),r(n+1,n);
	for(int i=1; i<=n; i++){
		if(st[i-1] == 'j') a[i] = a[i-1] - 1;
		else a[i] = a[i-1] + 1;
	}
	stack<int> stk;
	for(int i=0; i<=n; i++){
		while(!stk.empty() && a[stk.top()] > a[i]){
			r[stk.top()] = i-1;
			stk.pop();
		}
		stk.push(i);
	}
	while(!stk.empty()) stk.pop();
	for(int i=n; i>=0; i--){
		while(!stk.empty() && a[i] > a[stk.top()]){
			l[stk.top()] = i+1;
			stk.pop();
		}
		stk.push(i);
	}
	int ret = 0;
	vector<pair<int,int>> lis;
	for(int i=0; i<=n; i++) lis.push_back(pair<int,int>(l[i], i));
	sort(lis.begin(), lis.end());
	set<int> s;
	int p = 0;
	for(int i=0; i<=n; i++){
		while(p < lis.size() && lis[p].first <= i){
			s.insert(lis[p++].second);
		}
		auto t = s.upper_bound(r[i]);
		if(t != s.begin()){
			t--;
			ret = max(ret, *t - i);
		}
	}
    cout<<ret<<"\n";
}