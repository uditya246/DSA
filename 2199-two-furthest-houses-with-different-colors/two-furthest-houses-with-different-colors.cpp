class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int ans = 0;
        int left = colors[0];
        int right = colors[n-1];

        // Check max distance from the right end (fix against left color)
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != right) {
                ans = max(ans, n - 1 - i);
            }
        }

        // Check max distance from the left end (fix against right color)
        for (int i = n - 1; i > 0; i--) {
            if (colors[i] != left) {
                ans = max(ans, i);
            }
        }

        return ans;
    }
};