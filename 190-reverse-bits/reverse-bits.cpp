class Solution {
public:

    int reverseBits(int n) {
        string binary = "";
        for(int i = 0;i<32;i++){
            binary = char(n%2 + '0')+binary;
            n = n/2;
        }
        reverse(binary.begin(),binary.end());
        uint32_t ans = 0;
        for(int i = 0; i < 32; i++) {
            ans = ans * 2 + (binary[i] - '0');
        }

        
        return ans;
    }
};