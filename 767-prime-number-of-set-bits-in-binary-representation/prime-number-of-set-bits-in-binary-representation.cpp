class Solution {
public:
    bool isprime(int num){
        if(num<=1){
            return false;
        }
        for (int i = 2; i * i <= num; i++) {
            if (num% i == 0) {
                return false;
            }
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int count = 0;
        for(int i=left;i<=right;++i){
            int num = i;
            int bits = 0;
            while(num){
                if(num&1){
                    ++bits;
                }
                num>>=1;
            }
            if(isprime(bits)) count++;
        }
        return count;


    }
};