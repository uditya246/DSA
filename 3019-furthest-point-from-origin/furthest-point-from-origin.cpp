class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.length();
        int count = 0;
        int count2 = 0;
        for(auto it : moves){
            if(it == 'L'){
                count2++;
            }
            else if(it=='R'){
                count2--;
            }
            else{
                count++;
            }
        }
        count+=abs(count2);
        return count;
    }
};