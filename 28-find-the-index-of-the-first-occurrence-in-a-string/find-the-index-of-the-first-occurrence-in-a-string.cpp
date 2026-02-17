class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m == 0) return 0;
        if(n<m) return -1;
        int i = 0;
        int start = 0;
        int j = 0;
        while(i<n){
            if(haystack[i]==needle[j]){
                if(j==0) start = i;
                i++;
                j++;
                if(j==m) return start;
            }
            else{
                if(j==0){
                    i++;
                }
                else{
                    i=start+1;
                    j=0;
                }

            }
        }
        return -1;
    }
};