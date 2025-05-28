struct HLD {
    int timer;
    int n;
    vector < vector < int >> adj;
    vector < int > sub;
    vector < int > pos, head, par, depth, num;
    SegTree sg;
    void dfssz(int i = 0, int p = 0) {
        sub[i] = 1;
        for (auto & c: adj[i])
            if (c != p) {
                par[c] = i;
                depth[c] = depth[i] + 1;
                dfssz(c, i);
                sub[i] += sub[c];
                if (sub[c] > sub[adj[i][0]]) swap(c, adj[i][0]);
            }
    }
    void dfshld(int i = 0, int p = -1) {
        pos[i] = timer++;
        for (auto & c: adj[i])
            if (c != p) {
                head[c] = (c == adj[i][0] ? head[i] : c);
                dfshld(c, i);
            }
    }
    HLD(vector < vector < int >> & a, vector < int > & nu): timer(0), adj(a), n(a.size()), sub(n), pos(n), head(n), par(n), depth(n), num(n), sg(n) {
        par[0] = depth[0] = head[0] = 0;
        dfssz();
        dfshld();
        for (auto & i: pos) {
            num[pos[i]] = nu[i];
        }
        sg.build(0, 0, n - 1, num);
    }
    int query(int a, int b) {
        int ans = 0;
        for (; head[a] != head[b]; b = par[head[b]]) {
            if (depth[head[a]] > depth[head[b]]) swap(a, b);
            ans ^= sg.query(0, 0, n - 1, pos[head[b]], pos[b]);
        }
        if (depth[a] > depth[b]) swap(a, b);
        ans ^= sg.query(0, 0, n - 1, pos[a], pos[b]);
        return ans;
    }
    void update(int a, int b) {
        sg.update(0, 0, n - 1, pos[a], b);
    }
};