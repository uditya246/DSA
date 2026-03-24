class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];  // sort by end time
        });

        int count = 0;
        int prevEnd = intervals[0][1];

        for(int i = 1; i < n; i++){
            if(intervals[i][0] < prevEnd){
                // overlap → remove this interval
                count++;
            } else {
                // no overlap → keep it
                prevEnd = intervals[i][1];
            }
        }

        return count;
    }
};