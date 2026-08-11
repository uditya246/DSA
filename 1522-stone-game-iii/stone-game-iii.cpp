class Solution {
public:
    int solve(int i,int n,vector<int>& dp,vector<int>& suffix){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int best = INT_MIN;
        for(int x = 1;x<=3&&i+x<=n;x++){
            int nexti = i+x;
            int current = suffix[i]-suffix[nexti]-solve(nexti,n,dp,suffix);
            best = max(best,current);
        }
        return dp[i] = best;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int>dp(n,-1);
        vector<int>suffix(n+1,0);
        for(int i = n-1;i>=0;i--){
            suffix[i] = suffix[i+1]+stoneValue[i];
        }
        solve(0,n,dp,suffix);
        if(dp[0]>0) return "Alice";
        else if(dp[0]<0) return "Bob";
        return "Tie";

    }
};