class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans =0;
        while(n>0){
            int x = n%10;
            n = n/10;
            if(x!=0) ans = ans*10+x;
        }
        string s = to_string(ans);
        int sum = 0;
        for(int i = 0;i<s.size();i++){
            sum+=s[i]-'0';
        }
        reverse(s.begin(),s.end());
        ans = stoll(s);
        return ans*sum;
    }
};