class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int i = cost.size()-1;
        int ans = 0;
        if(i<1) return cost[0];
        while(i>=0){
            if(i<1){
                ans+= cost[0];
                break;
            }
            ans = ans+cost[i]+cost[i-1];
            i = i-3;
        }
        return ans;
    }
};