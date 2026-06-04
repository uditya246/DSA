class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>>& vis,vector<int>&r,vector<int>&c){
        vis[row][col]=1;
        for(int i = 0;i<4;i++){
            int nrow = row+r[i];
            int ncol = col+c[i];
            if(nrow >= 0 && nrow < grid.size() &&ncol >= 0 && ncol < grid[0].size() &&grid[nrow][ncol]=='1'&&!vis[nrow][ncol]){
                dfs(nrow,ncol,grid,vis,r,c);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>r = {-1,0,1,0};
        vector<int>c = {0,1,0,-1};
        vector<vector<int>>vis(m,vector<int>(n,0));
        int count = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!vis[i][j]&&grid[i][j]=='1'){
                    dfs(i,j,grid,vis,r,c);
                    count++;
                }
            }
        }
        return count;
    }
};