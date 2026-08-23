class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int rightsum = 0;
        int rightchar = 0;
        int leftsum = 0;
        int leftchar = 0;
        for(int i = 0;i<n/2;i++){
            if(num[i]=='?'){
                leftchar++;
            }
            else{
                leftsum+=num[i]-'0';
            }

        }
        for(int i = n/2;i<n;i++){
            if(num[i]=='?'){
                rightchar++;

            }
            else{
                rightsum+=num[i]-'0';
            }
        }
        if((leftchar+rightchar)%2==1) return true;
        int sumdiff = leftsum-rightsum;
        int chardiff = rightchar-leftchar;
        return sumdiff != chardiff*9/2;
    }
};