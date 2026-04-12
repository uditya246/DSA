class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n =nums.size();
        for(int i =0;i<n;i =i+1){
            int j = i+1;
            while(j<n&&j<=i+k){
                if(nums[i]==nums[j]) return true;
                j++;
            }
        }
        return false;

    }
};