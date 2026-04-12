class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(!n) return false;
        int x = nums[n-1];
        n--;
        while(n>0){
            int t = nums[n-1];
            if(t==x) return true;
            n--;
            x = t;
        }
        return false;
    }
};