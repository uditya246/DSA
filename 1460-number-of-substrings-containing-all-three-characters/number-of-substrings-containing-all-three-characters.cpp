class Solution {
public:
    int numberOfSubstrings(string s) {
        int r= 0;
        int a = -1;//storing their last seen indexes
        int b = -1;
        int c = -1;
        int ans =0;
        while(r<s.size()){
            if(s[r]=='a') a = r;
            if(s[r]=='b') b=r;
            if(s[r]=='c') c=r;
            if(a>-1&&b>-1&&c>-1){
                ans += min(min(a,b),c)+1;
            }
            r++;
        }
        return ans;
    }
};