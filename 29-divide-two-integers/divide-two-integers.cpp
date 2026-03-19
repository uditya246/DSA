class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        bool sign = 1;
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        if(dividend>=0&&divisor<0) sign = 0;
        else if(dividend<0&&divisor>0) sign= 0;
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long long ans = 0;
        while(n>=d){
            int count = 0;
            while(n>=(d<<(count+1))){
                count++;
            }
            ans +=(1LL<<count);
            n-= (d<<count);
        }
        if(ans==(1LL<<31)&&sign){
            return INT_MAX;
        }
        else if(ans==1LL<<31&&!sign){
            return INT_MIN;
        }
        
        return sign?ans:-1*ans;
    }
};