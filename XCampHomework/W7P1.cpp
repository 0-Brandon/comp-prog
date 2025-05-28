#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

const int inf = 1e9;

void solve() {
    int n, m, w;
    cin >> n >> m >> w;
    vector< vector<int> > edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--, b--;
        edges.push_back(vector<int>(3));
        edges.back()[0] = a;
        edges.back()[1] = b;
        edges.back()[2] = c;
        edges.push_back(vector<int>(3));
        edges.back()[0] = b;
        edges.back()[1] = a;
        edges.back()[2] = c;
    }
    for (int i = 0; i < w; i++) {
        int a, b, c; cin >> a >> b >> c; a--, b--;
        edges.push_back(vector<int>(3));
        edges.back()[0] = a;
        edges.back()[1] = b;
        edges.back()[2] = -c;
    }
    vector<int> d(n);
    bool b;
    for (int j = 0; j < n; j++) {
        b=true;
        for (int k = 0; k < edges.size(); k++) {
            if (d[edges[k][0]] < inf)
                if (d[edges[k][1]] > d[edges[k][0]] + edges[k][2]) {
                    d[edges[k][1]] = max(-inf, d[edges[k][0]] + edges[k][2]);
                    b=false;
                }
        }
    }
    if(!b)cout<<"YES\n";
    else cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
