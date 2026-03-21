class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int l = 0;
        int r = 0;
        int maxf = 0;
        unordered_map<char,int>mp;
        while(r<s.size()){
            mp[s[r]]++;
            maxf = max(maxf,mp[s[r]]);
            int changes = r-l+1-maxf;
            if(changes<=k){
                ans = max(ans,r-l+1);
            }
            else{
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};