class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int x = s.size();
        int maxi = INT_MIN;
        int maxi2 = INT_MIN;
        for(int i = 0;i<x;i++){
            if(s[i]-'0'>=maxi){
                maxi2 = maxi;
                maxi = s[i]-'0';
            }
            else if(s[i]-'0'>maxi2){
                maxi2 = s[i]-'0';
            }
        }
        return maxi2*maxi;
    }
};