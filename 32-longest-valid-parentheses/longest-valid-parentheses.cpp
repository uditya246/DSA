class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        int curr = 0;
        stack<int> st;

        st.push(-1);

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();

                if (st.empty()) {
                    // Current valid sequence is broken
                    st.push(i);
                    curr = 0;
                }
                else {
                    // Length of current valid substring
                    curr = i - st.top();
                    ans = max(ans, curr);
                }
            }
        }

        return ans;
    }
};