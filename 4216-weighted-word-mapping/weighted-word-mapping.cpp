class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto it : words){
            int total = 0;
            for(auto s : it){
                total+=weights[s-'a'];
            }
            total = total%26;
            char x = 'a'+25-total;
            ans += x;
        }
        return ans;
    }
};