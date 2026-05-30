class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        int x = 2e9;
        int row = 0;
        int col = 0;
        dp[0][0] = 1;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i == 0 && j == 0) continue;
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i>0&&j>0){
                    if(x<dp[i-1][j]+dp[i][j-1]){
                        return x;
                    }
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
                else if(j==0){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
        // int s = 2;
        // if(row==0||row == m-1||col==0||col == n-1) s=1;
        return dp[m-1][n-1];
    }
};