class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int count = 0;
        int l = 0;
        int r = 0;
        int countodds = 0;
        while(r<nums.size()){
            if(nums[r]%2) countodds++;
            
            while(countodds>k){
                if(nums[l]%2) countodds--;
                l++;
            }
            count +=r-l+1;
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};