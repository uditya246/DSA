class Solution {
public:
    void solve(vector<string>& ans, int n, string s, char x) {
        if(s.size() == n) {
            ans.push_back(s);
            return;
        }

        if(x == '#') {
            solve(ans, n, s + "a", 'a');
            solve(ans, n, s + "b", 'b');
            solve(ans, n, s + "c", 'c');
        }
        else {
            if(x == 'a') {
                solve(ans, n, s + "b", 'b');
                solve(ans, n, s + "c", 'c');
            }
            else if(x == 'b') {
                solve(ans, n, s + "a", 'a');
                solve(ans, n, s + "c", 'c');
            }
            else {
                solve(ans, n, s + "a", 'a');
                solve(ans, n, s + "b", 'b');
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;

        solve(ans, n, "", '#');

        if(ans.size() < k)
            return "";

        return ans[k - 1];
    }
};