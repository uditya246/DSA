class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        
        int n = arr.size();
        
        vector<int> dp(n, 1);
        
        vector<pair<int,int>> v;
        
        for(int i = 0; i < n; i++) {
            v.push_back({arr[i], i});
        }
        
        sort(v.begin(), v.end());
        
        int ans = 1;
        
        for(auto &it : v) {
            
            int i = it.second;
            
            bool decF = true;
            bool decB = true;
            
            for(int j = 1; j <= d; j++) {
                
                // right
                if(i + j < n && decF) {
                    
                    if(arr[i+j] < arr[i]) {
                        dp[i] = max(dp[i], 1 + dp[i+j]);
                    }
                    else {
                        decF = false;
                    }
                }
                
                // left
                if(i - j >= 0 && decB) {
                    
                    if(arr[i-j] < arr[i]) {
                        dp[i] = max(dp[i], 1 + dp[i-j]);
                    }
                    else {
                        decB = false;
                    }
                }
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};