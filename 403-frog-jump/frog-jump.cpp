class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        dp[0][1]=1;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                int jump = stones[i]-stones[j];
                if(jump<0||jump>n||!dp[j][jump]) continue;
                dp[i][jump] = 1;
                if(jump-1>=0) dp[i][jump-1] = 1;
                if(jump+1<=n) dp[i][jump+1] = 1;
                if(i == n-1) return true;
            }
        }
        return false;

    }
};