class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int m = nums.size();
        
        // Step 1: store positions
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < m; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> answer;
        
        for (int q : queries) {
            int val = nums[q];
            auto &vec = mp[val];
            
            // if only one occurrence
            if (vec.size() == 1) {
                answer.push_back(-1);
                continue;
            }
            
            // binary search
            int idx = lower_bound(vec.begin(), vec.end(), q) - vec.begin();
            
            int prev = (idx == 0) ? vec.back() : vec[idx - 1];
            int next = (idx == vec.size() - 1) ? vec[0] : vec[idx + 1];
            
            // circular distances
            int dist1 = abs(q - prev);
            int dist2 = abs(q - next);
            
            dist1 = min(dist1, m - dist1);
            dist2 = min(dist2, m - dist2);
            
            answer.push_back(min(dist1, dist2));
        }
        
        return answer;
    }
};


// class Solution {
// public:
//     vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
//         int n = queries.size();
//         int m = nums.size();
//         vector<int>answer(n,-1);
//         for(int j = 0;j<n;j++){
//             int startIndex = queries[j];
//             int i = (startIndex+1)%m;
//             int mini = INT_MAX;
//             while(i!=startIndex){
//                 if(nums[startIndex] ==nums[i]){
//                     int left = (m-i+startIndex)%m;
//                     int right = i<startIndex?m-startIndex+i:i-startIndex;
//                     mini = min(min(right,left),mini);
//                 }
//                 i = (i+1)%m;
//             }
//             answer[j] = mini==INT_MAX?-1:mini; 
//         }
//         return answer;
//     }
// };