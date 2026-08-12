class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int i =0;
        int j = 0;
        int ans = 0;
        while(j<n){
            mp[nums[j]]++;
            while(i<n&&mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }
            ans = max(j-i+1,ans);
            j++;
        }
        return ans;
        
    }
};