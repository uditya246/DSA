class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        int n = numCourses;
        vector<int> indegree(n,0);

        for(int i=0;i<n;i++){

            for(auto nxt:adj[i]){

                indegree[nxt]++;

            }

        }
        vector<int> topo;

        for(int i=0;i<n;i++){
        
            if(indegree[i]==0)

                q.push(i);

        }

        while(!q.empty()){
        
            int node=q.front();

           q.pop();

           topo.push_back(node);

            for(auto nxt:adj[node]){
            
                indegree[nxt]--;

                if(indegree[nxt]==0){

                    q.push(nxt);
                }

            }

        }
        if(topo.size()!=numCourses) return false;
        return true;

    }
};