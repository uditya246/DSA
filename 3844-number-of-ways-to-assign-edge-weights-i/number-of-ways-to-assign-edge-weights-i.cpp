class Solution {
public:

    long long power(long long a, long long b) {
        const long long MOD = 1e9 + 7;

        long long res = 1;

        while(b > 0) {

            if(b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;

            b >>= 1;
        }

        return res;
    }

    void solve(int depth,
               vector<vector<int>>& adj,
               vector<int>& vis,
               int& maxdepth,
               int curr) {

        vis[curr] = 1;

        maxdepth = max(maxdepth, depth);

        for(auto it : adj[curr]) {

            if(!vis[it]) {
                solve(depth + 1,
                      adj,
                      vis,
                      maxdepth,
                      it);
            }
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);

        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n + 1, 0);

        int maxdepth = 0;

        solve(0, adj, vis, maxdepth, 1);

        return power(2, maxdepth - 1);
    }
};