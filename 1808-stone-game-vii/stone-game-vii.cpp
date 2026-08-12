class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        vector<int>left(n,0),right(n,0);
        left[0] = 0;
        right[n-1] = 0;
        for(int i = 1;i<n;i++){
            left[i] = left[i-1]+stones[i-1];
        }
        for(int j = n-2;j>=0;j--){
            right[j] = right[j+1]+stones[j+1];
        }
        for(int len = 2;len<=n;len++){
            for(int i = 0;i+len-1<n;i++){
                int j = i+len-1;
                int l = right[i]-right[j]-dp[i+1][j];

                int r = left[j]-left[i]-dp[i][j-1];
                dp[i][j] = max(l,r);
            }
        }
        return dp[0][n-1];

    }
};