class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for(auto it:moves){
            if(it=='U') y++;
            else if(it=='D') y--;
            else if(it=='L') x++;
            else x--;
        }
        if(x==0&&y==0) return true;
        return false;
    }
};