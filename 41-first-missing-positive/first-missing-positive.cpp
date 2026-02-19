class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool one = false;
        for(int i = 0;i<n;i++){
            if(nums[i]==1) one =true;
            if(nums[i]<=0||nums[i]>n) nums[i]=1;
        }
        if(!one) return 1;
        for(int i = 0;i<n;i++){
            int ind = abs(nums[i])-1;
            nums[ind] = -abs(nums[ind]);
        }
        
        for(int i = 0;i<n;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};