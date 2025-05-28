/*
binary search length of range
for each index i,
gcd(i to i+l) must be in range
*/

#include <bits/stdc++.h>
constexpr int LOG = 20;
using namespace std;
int n;
vector < int > x;
vector < int > ans;
vector<vector<int>> gst, mst;

int gquery(int i, int j){
    int b = 31 - __builtin_clz(j-i+1);
    return gcd(gst[b][i],gst[b][j-(1<<b)+1]);
}
int mquery(int i, int j){
    int b = 31-__builtin_clz(j-i+1);
    return min(mst[b][i], mst[b][j-(1<<b)+1]);
}
bool ok(int l) {
  bool b = false;
  ans.clear();
  for(int i=0; i+l-1<n; i++){
    if(gquery(i,i+l-1)==mquery(i,i+l-1)){
        ans.push_back(i);
        b=true;
    }
  }
  return b;
}
int main() {
  cin >> n;
  x.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  mst.resize(LOG,vector<int>(n));
  gst.resize(LOG,vector<int>(n));
  copy(x.begin(),x.end(),mst[0].begin());
  copy(x.begin(),x.end(),gst[0].begin());
  for(int i=1; i<LOG; i++){
    for(int j=0; j+(1<<i)<=n; j++){
        mst[i][j] = min(mst[i-1][j],mst[i-1][j+(1<<(i-1))]);
        gst[i][j] = gcd(gst[i-1][j],gst[i-1][j+(1<<(i-1))]);
    }
  }
  int l = 0, h = n;
  while (l < h) {
    int mid = l + (h - l+1) / 2;
    if (ok(mid)) {
      l = mid;
    } else h = mid - 1;
  }
  ok(l);
  cout<<ans.size()<<" "<<l-1<<"\n";
  for (auto & i: ans) {
    cout << i+1 << " ";
  }
}