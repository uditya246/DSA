class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a, b;

        a.push_back(nums[0]);
        b.push_back(nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            if (a.back() > b.back()) {
                a.push_back(nums[i]);
            } else {
                b.push_back(nums[i]);
            }
        }

        vector<int> ans;

        for (int x : a)
            ans.push_back(x);

        for (int x : b)
            ans.push_back(x);

        return ans;
    }
};