class Solution {
public:
int countBits(int n){
    int count = 0;
    while(n > 0){
        count++;
        n = n >> 1;
    }
    return count;
}
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int x = n;
        int count = countBits(n);
        int mask = (1<<count) -1;
        return x^mask;
    }
};