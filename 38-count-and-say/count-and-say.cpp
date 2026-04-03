class Solution {
public:
    string func(vector<vector<int>>&arr){
        string s = "";
        for(auto it:arr){
            s += to_string(it[1]); // count
            s += to_string(it[0]); // number
        }
        return s;
    }
    void frequency(string s,vector<vector<int>>&arr){
        char c = s[0];
        int count = 1;
        for(int i = 1;i<s.size();i++){
            if(s[i]==c){
                count++;
            }
            else{
                arr.push_back({c-'0',count});
                c = s[i];
                count = 1;
            }
        }
        arr.push_back({c - '0', count});

    }
    string countAndSay(int n) {
        string ans = "1";
        
        for(int i = 2;i<=n;i++){
            vector<vector<int>>arr;
            frequency(ans,arr);
            ans = func(arr);
        }
        return ans;
    }
};