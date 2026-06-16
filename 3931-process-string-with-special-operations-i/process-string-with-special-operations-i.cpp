class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string result = "";
        for(int i = 0;i<n;i++){
            if(s[i]-'a'<26&&s[i]-'a'>=0){
                result +=s[i];
            }
            else if(s[i]=='*'){
                int n = result.size();
                if(n>0){
                    result.pop_back();
                }
            }
            else if(s[i]=='#'){
                string x = result;
                result+=x;
            }
            else{
                reverse(result.begin(),result.end());
            }
        }
        return result;
    }
};