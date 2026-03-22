class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int>mp;
        int five = 0 ;
        int ten = 0;
        for(auto it: bills){
            if(it==5){
                five++;
            }
            else if(it==10){
                ten++;
                if(!five) return false;
                else{
                    five--;
                } 
            }
            else if(it==20){
                if(!ten&&!five) return false;
                else if(ten&&!five) return false;
                else if(ten&&five){
                    ten--;
                    five--;
                }
                else if(!ten&&five){
                    if(five>=3)five-=3;
                    else return false;
                }
            }
        }
        return true;
    }
};