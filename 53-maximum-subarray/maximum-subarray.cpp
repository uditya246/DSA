class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int sum = 0;
        int i = 0;
        while(i<n){
            sum+=nums[i];
            ans = max(ans,sum);
            if(sum<0){
                sum=0;
            }
            i++;
            
        }
        return ans;
    }
};