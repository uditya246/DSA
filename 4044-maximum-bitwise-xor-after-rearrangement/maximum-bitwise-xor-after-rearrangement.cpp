// 
class Solution {
public:
    string maximumXor(string s, string t) {

        int count0 = 0, count1 = 0;

        for(char c : t) {
            if(c == '0') count0++;
            else count1++;
        }

        string result = "";

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '0') {
                if(count1 > 0) {
                    result += '1';
                    count1--;
                } else {
                    result += '0';
                    count0--;
                }
            }
            else { // s[i] == '1'
                if(count0 > 0) {
                    result += '1';
                    count0--;
                } else {
                    result += '0';
                    count1--;
                }
            }
        }

        return result;
    }
};