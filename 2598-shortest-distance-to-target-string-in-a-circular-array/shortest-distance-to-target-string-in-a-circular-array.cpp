class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int i = (startIndex+1)%n;
        if(target ==words[startIndex]) return 0;
        int ans = INT_MAX;
        while(i!=startIndex){
            if(target ==words[i]){
                int left = (n-i+startIndex)%n;
                int right = i<startIndex?n-startIndex+i:i-startIndex;
                int mini = min(right,left);
                ans = min(ans,mini);
            }
            i = (i+1)%n;
        }
        return ans==INT_MAX?-1:ans;
    }
};