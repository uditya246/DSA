class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int n = gain.size();
        int curr = 0;
        for(int i = 0;i<n;i++){
            curr +=gain[i];
            ans = max(ans,curr);
        }
        return ans;
    }
};