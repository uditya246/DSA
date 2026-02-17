class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int i = digits.size()-1;
        if(i<0) return digits;
        int summ = digits[i]+1;
        int carry = (summ)/10;
        digits[i] = (summ)%10;
        
        i--;

        while(i>=0&&carry){
            int sum = digits[i]+carry;
            carry = (sum)/10;
            digits[i] = (sum)%10;
            i--;
        }
        if(carry!=0) digits.insert(digits.begin(),carry);
        return digits;

    }
};