class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        queue<int>q;
        int ans = INT_MAX;
        vector<int>vis(n+1,0);
        q.push(1);
        vis[1] = 1;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto it:adj[x]){
                int y = it.first;
                ans = min(ans,it.second);
                if(!vis[y]){
                    vis[y] = 1;
                    q.push(y);
                }
            }
        }
        return ans;
    }
};