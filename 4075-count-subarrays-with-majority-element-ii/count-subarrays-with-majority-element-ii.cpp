// class Solution {
// public:
//     long long countMajoritySubarrays(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int>arr(n,-1);
//         for(int i = 0;i<n;i++){
//             if(nums[i]==target){
//                 arr[i] = 1;
//             }
//         }
//         vector<int>pref(n+1,0);
//         for(int i=1;i<=n;i++){
//             pref[i] = pref[i-1]+arr[i-1];
//         }

//         long long ans = 0;
//         for(int i = 0;i<n;i++){
//             for(int j =i+1;j<=n;j++){
//                 if(pref[j]>pref[i]) ans++;
//             }
//         }
//         return ans;

//     }
// };
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int size = nums.size(), pref = size;

        vector<int> freq(2 * size + 1);
        freq[size] = 1;

        long long less = 0, ans = 0;

        for (int num : nums) {
            if (num == target)
                less += freq[pref++];
            else
                less -= freq[--pref];

            ++freq[pref];
            ans += less;
        }

        return ans;
    }
};