class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>smaller;
        vector<int>greater;
        int equal =  0;
        int n = nums.size();
        for(auto it: nums){
            if(it<pivot){
                smaller.push_back(it);
            }
            else if(it==pivot){
                equal++;
            }
            else{
                greater.push_back(it);
            }
        }
        int i = 0;
        while(i<smaller.size()){
            nums[i] = smaller[i];
            i++;
        }
        while(equal!=0){
            nums[i] = pivot;
            i++;
            equal--;
        }
        int x = i;
        while(i<n){
            nums[i] = greater[i-x];
            i++;
        }
        return nums;


    }
};