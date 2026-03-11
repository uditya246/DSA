class Solution {
public:

    int findComplement(int num) {
        int count = 0;
        if(num==0) return 1;
        int n = num;
        while(n>0){
            count++;
            n = n>>1;
        }
        long long mask = (1LL << count) - 1;
        return num^mask;
        
    }
};