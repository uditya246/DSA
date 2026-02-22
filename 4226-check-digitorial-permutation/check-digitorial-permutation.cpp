class Solution {
public:
    int factorial(int x) {
        int fact = 1;
        for(int i = 1; i <= x; i++) {
            fact *= i;
        }
        return fact;
    }
    
    
    bool isDigitorialPermutation(int n) {
        if(n<=0) return false;
        string s = to_string(n);
        sort(s.begin(),s.end());
        while(true){
            if(s[0]=='0'){
                next_permutation(s.begin(), s.end());
                continue;
            }
            int number = stoi(s);
            int sum = 0;
            for(int i = 0;i<s.size();i++){
                sum+=factorial(s[i]-'0');
            }
            if(sum==number){
                return true;
            }

            if(!next_permutation(s.begin(),s.end())) break;
        }
        return false;
        
    }
};