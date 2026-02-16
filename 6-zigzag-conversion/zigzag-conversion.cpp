class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1||numRows>=s.size()){
            return s;
        }
        vector<string>rows(numRows);
        int currow = 0;
        bool goindown = false;
        for(char c:s){
            rows[currow] +=c;
            if(currow==0||currow==numRows-1){
                goindown = !goindown;
            }
            currow += goindown? 1:-1;
        }
        string ans = "";
        for(string row:rows){
            ans+=row;
        }
        return ans;
    }
};