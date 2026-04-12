class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // int n =nums.size();
        // for(int i =0;i<n;i =i+1){
        //     int j = i+1;
        //     while(j<n&&j<=i+k){
        //         if(nums[i]==nums[j]) return true;
        //         j++;
        //     }
        // }
        // return false;
        unordered_set<int> set;
        
        for (int i = 0; i < nums.size(); ++i) {
            // Remove the element that is now outside the window
            if (i > k) {
                set.erase(nums[i - k - 1]);
            }
            
            // Check if the current element exists in the set
            if (set.count(nums[i])) {
                return true;
            }
            
            // Add the current element to the set
            set.insert(nums[i]);
        }
        
        return false;

    }
};