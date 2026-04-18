class Solution {
public:
    int reverse_number(int n){
        string s = to_string(n);
        reverse(s.begin(),s.end());
        return stoi(s);

    }
    int mirrorDistance(int n) {
        return abs(n-reverse_number(n));
    }
};