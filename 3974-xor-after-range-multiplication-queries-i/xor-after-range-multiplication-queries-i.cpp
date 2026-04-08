class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9+7;
        int n = nums.size();
        int q = queries.size();
        for(auto it:queries){
            int idx = it[0];
            while(idx<=it[1]&&idx<n){
                long long temp = nums[idx];
                nums[idx] = (temp*it[3])%(mod);
                idx+=it[2];
            }
        }
        int ans=0;
        for(auto it : nums){
            ans = ans^it;
        }
        return ans;
    }
};