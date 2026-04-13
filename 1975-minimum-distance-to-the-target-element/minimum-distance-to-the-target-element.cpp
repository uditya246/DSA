class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans = INT_MAX;
        int i = start-1;
        int j = start+1;
        int foundi = false;
        int foundj = false;
        if(nums[start]==target) return 0;
        while(i>=0&&!foundi){
            if(nums[i]==target){
                foundi=true;
                ans = min(ans,abs(i-start));
            }
            i--;
        }
        while(j<nums.size()&&!foundj){
            if(nums[j]==target){
                foundj=true;
                ans = min(ans,abs(j-start));
            }
            j++;
        }
        return ans;
    }
};