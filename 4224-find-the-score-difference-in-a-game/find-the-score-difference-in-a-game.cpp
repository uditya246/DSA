class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int player1 = 0;
        int player2 = 0;
        bool one  = true;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(((i+1)%2==0&&(i+1)%3==0)){
                one = !one;
            }
            if(nums[i]%2){
                one = !one;
            }
            if(one){
                player1+=nums[i];
            }
            else{
                player2 +=nums[i];
            }
        }
        return player1-player2;
    }
};