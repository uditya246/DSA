class Solution {
public:
    bool solve(vector<int>& arr, int start, vector<int>& vis) {
        int n = arr.size();

        if(start < 0 || start >= n || vis[start]) return false;

        if(arr[start] == 0) return true;

        vis[start] = 1;

        return solve(arr, start + arr[start], vis) ||
               solve(arr, start - arr[start], vis);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n, 0);

        return solve(arr, start, vis);
    }
};