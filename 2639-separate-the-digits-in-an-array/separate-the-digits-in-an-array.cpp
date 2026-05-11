class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0;i<n;i++){
            int x = nums[i];
            string y = to_string(x);
            for(int j = 0;j<y.size();j++){
                ans.push_back(y[j]-'0');
            }
        }
        return ans;
    }
};