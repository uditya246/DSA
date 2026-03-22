class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>mp;
        for(auto it: bills){
            if(it==5){
                mp[it]++;
            }
            else if(it==10){
                mp[it]++;
                if(!mp[5]) return false;
                else{
                    mp[5]--;
                } 
            }
            else if(it==20){
                if(!mp[10]&&!mp[5]) return false;
                else if(mp[10]&&!mp[5]) return false;
                else if(mp[10]&&mp[5]){
                    mp[10]--;
                    mp[5]--;
                }
                else if(!mp[10]&&mp[5]){
                    for(int i = 0;i<3;i++){
                        if(!mp[5]) return false;
                        else mp[5]--;
                    }
                }
            }
        }
        return true;
    }
};