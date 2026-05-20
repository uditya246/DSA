class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans(n,0);
        vector<int>vis(n+1,0);
        int coms = 0;
        for(int i = 0;i<n;i++){
            if(A[i]==B[i]){
                coms++;
                if(i>0){
                    ans[i] = ans[i-1]+1;
                }
                else{
                    ans[0] = 1;
                }
                
                
            }
            else{
                if(vis[A[i]])coms++;
                else vis[A[i]] = 1;

                if(vis[B[i]])coms++;
                else vis[B[i]] = 1;
                ans[i] = coms;

            }
        }
        return ans;
    }
};