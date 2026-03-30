class Solution {
public:
    bool canBeEqual(string s1, string s2) {
       
        for(int i = 0;i<2;i++){
            if(s1[i]==s2[i+2]&&s1[i+2]==s2[i]){
                char temp = s1[i];
                s1[i] = s1[i+2];
                s1[i+2] = temp;
                
            }
        }
        if(s1==s2) return true;
        return false;
    }
};