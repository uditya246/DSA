class Solution {
public:

    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        if(s.size()<=k) return false;
        for(int i = 0;i<=s.size()-k;i++){
            st.insert(s.substr(i,k));
        }
        int n = st.size();
        return n ==1<<k;
    }
};