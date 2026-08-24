class Solution {
public:
    int maxdiff(int i, vector<int>& s, vector<int>& dp) {
        if (i == s.size() - 1)
            return s[i];

        if (dp[i] != INT_MIN)
            return dp[i];

        int next = maxdiff(i + 1, s, dp);

        return dp[i] = max(next, s[i] - next);
    }

    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> s(n);
        s[0] = stones[0];

        for (int i = 1; i < n; i++)
            s[i] = s[i - 1] + stones[i];

        vector<int> dp(n, INT_MIN);

        return maxdiff(1, s, dp);
    }
};