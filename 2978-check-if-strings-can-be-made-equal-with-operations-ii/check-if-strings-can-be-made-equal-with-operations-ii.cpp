class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        unordered_map<char,int>even;
        unordered_map<char,int>odd;
        for(int i=0;i<n;i++){
            if(i%2){
                odd[s2[i]]++;
            }
            else{
                even[s2[i]]++;
            }
        }
        for(int j = 0;j<n;j++){
            if(j%2){
                odd[s1[j]]--;
            }
            else{
                even[s1[j]]--;
            }
        }
        for(auto it:odd){
            if(it.second!=0) return false;
        }
        for(auto it : even){
            if(it.second!=0) return false;
        }
        return true;

    }
};