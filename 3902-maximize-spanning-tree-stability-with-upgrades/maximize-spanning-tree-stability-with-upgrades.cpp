class Solution {
    struct DSU{
        int totalnode;
        vector<int>parent;
        vector<int>size;
        DSU(int n){
            totalnode = n;
            size.resize(n,1);
            parent.resize(n);
            for(int i = 0;i<n;i++){
                parent[i] = i;
            }
        }
        int find(int ind){
            if(parent[ind]!=ind){
                parent[ind] = find(parent[ind]);
            }
            return parent[ind];
        }
        bool merge(int n1,int n2){
            int g1 = find(n1);
            int g2 = find(n2);
            if(g1==g2) return false;
            if(size[g2]>size[g1]){
                swap(g1,g2);
            }
            parent[g2] = g1;
            size[g1] +=size[g2];
            totalnode--;
            return true;
        }
    };
public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int minstrength = INT_MAX;
        vector<int> candEdge;
        for(int i = 0;i<edges.size();i++){
            vector<int> edge = edges[i];
            if(edge[3]==0){
                candEdge.push_back(i);
            }
            else{
                minstrength = min(minstrength,edge[2]);
                if(dsu.merge(edge[0],edge[1])==false){
                    return -1;
                }
            }
        }

        sort(candEdge.begin(), candEdge.end(), [&](int a, int b){
            return edges[a][2] > edges[b][2];
        });
        vector<int>pickstrength;
        for(auto ind : candEdge){
            int u = edges[ind][0];
            int v = edges[ind][1];
            if(dsu.merge(u,v)){
                pickstrength.push_back(edges[ind][2]);
                if(dsu.totalnode==1) break;
            }
        }
        if(k&&!pickstrength.empty()){
            minstrength = min(minstrength,pickstrength.back()*2);
        }
        if(pickstrength.size()>k){
            minstrength = min(minstrength,pickstrength[pickstrength.size()-1-k]);
        }
        return dsu.totalnode ==1 ? minstrength:-1;
    }
};