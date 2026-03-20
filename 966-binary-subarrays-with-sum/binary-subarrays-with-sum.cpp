class Solution {
public:
    int atmost(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int ans = 0;
        int sum = 0;
        int start = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            sum+=nums[i];
            while(sum>goal){
                sum-=nums[start];
                start++;
            }
            ans+=i-start+1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal)-atmost(nums,goal-1);
    }
};