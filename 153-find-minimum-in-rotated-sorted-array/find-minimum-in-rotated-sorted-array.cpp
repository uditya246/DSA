class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while(low < high) {
            int mid = (low + high) / 2;

            // array already sorted
            if(nums[low] < nums[high]) {
                return nums[low];
            }

            // minimum is in right part
            if(nums[mid] >= nums[low]) {
                low = mid + 1;
            }
            // minimum is in left part including mid
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};