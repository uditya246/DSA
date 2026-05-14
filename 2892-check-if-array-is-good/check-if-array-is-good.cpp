class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int>freq(n,0);
        for(auto it : nums){
            if(it >= n) return false;
            freq[it]++;
        }
        if(freq[n-1]!=2) return false;
        for(int i = n-2;i>0;i--){
            if(freq[i]!=1) return false;
        }
        return true;
    }
};