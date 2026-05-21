class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<string> st;

        for(int x : arr1){

            string s = to_string(x);
            string temp = "";

            for(char ch : s){
                temp += ch;
                st.insert(temp);
            }
        }

        int ans = 0;

        for(int x : arr2){

            string s = to_string(x);
            string temp = "";

            for(int i = 0; i < s.size(); i++){

                temp += s[i];

                if(st.count(temp)){
                    ans = max(ans, i + 1);
                }
            }
        }

        return ans;
    }
};