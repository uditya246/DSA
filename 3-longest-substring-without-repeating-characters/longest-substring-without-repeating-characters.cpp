class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        int maxi = 0;
        int start = 0;
        for(int i = 0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                
                start = max(start,mp[s[i]]+1);

            }
            mp[s[i]] = i;
            maxi = max(maxi,i-start+1);
        }
        return maxi;
    }
};