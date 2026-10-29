class Solution {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> tin, tout, depth;
    vector<vector<int>> up;
    vector<int> bit;
    string chars;
    int LOG;

    void dfs(int u, int p, int d) {
        tin[u] = timer++;
        depth[u] = d;
        up[0][u] = p;
        for (int v : adj[u]) {
            if (v != p) dfs(v, u, d + 1);
        }
        tout[u] = timer - 1;
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int lca(int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;
        for (int i = LOG; i >= 0; i--) {
            if (!isAncestor(up[i][u], v)) u = up[i][u];
        }
        return up[0][u];
    }

    void updateBIT(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] ^= val;
    }

    int queryBIT(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx) res ^= bit[idx];
        return res;
    }

    void rangeXor(int l, int r, int val) {
        updateBIT(l + 1, val);
        updateBIT(r + 2, val);
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        this->chars = s;
        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 31 - __builtin_clz(n);
        up.assign(LOG + 1, vector<int>(n));
        tin.resize(n); tout.resize(n); depth.resize(n);
        timer = 0;
        dfs(0, 0, 0);

        for (int i = 1; i <= LOG; i++) {
            for (int j = 0; j < n; j++) {
                up[i][j] = up[i - 1][up[i - 1][j]];
            }
        }

        bit.assign(n + 2, 0);
        for (int i = 0; i < n; i++) {
            int mask = 1 << (s[i] - 'a');
            rangeXor(tin[i], tout[i], mask);
        }

        vector<bool> ans;
        for (string& q : queries) {
            if (q[0] == 'u') {
                int u; char c;
                sscanf(q.c_str(), "update %d %c", &u, &c);
                if (c != chars[u]) {
                    int oldMask = 1 << (chars[u] - 'a');
                    int newMask = 1 << (c - 'a');
                    int diff = oldMask ^ newMask;
                    rangeXor(tin[u], tout[u], diff);
                    chars[u] = c;
                }
            } else {
                int u, v;
                sscanf(q.c_str(), "query %d %d", &u, &v);
                int l = lca(u, v);
                int maskU = queryBIT(tin[u] + 1);
                int maskV = queryBIT(tin[v] + 1);
                int maskL = 1 << (chars[l] - 'a');
                int pathMask = maskU ^ maskV ^ maskL;
                
                // At most 1 bit set → palindrome possible
                if (__builtin_popcount(pathMask) <= 1) ans.push_back(true);
                else ans.push_back(false);
            }
        }
        return ans;
    }
};