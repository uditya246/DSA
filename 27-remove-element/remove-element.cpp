class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        while(i<=j){
            while(i<=j&&nums[j]==val){
                j--;
            }
            if(i<=j&&nums[i]==val){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                j--;
            }
            else{
                i++;
            }
        }
        return j+1;
    }
};