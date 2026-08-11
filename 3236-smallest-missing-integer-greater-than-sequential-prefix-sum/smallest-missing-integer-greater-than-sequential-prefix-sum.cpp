class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int prefsum = nums[0];
        
        for(int i = 1;i<nums.size();i++){
            if(nums[i]==nums[i-1]+1){
                prefsum+=nums[i];
            }
            else{
                break;
            }
        }
        sort(nums.begin(),nums.end());
        int ans = prefsum;
        int j = 0;
        while(j<nums.size()){
            if(nums[j]==ans){
                ans++;
            }
            j++;
        }
        return ans;

    }
};