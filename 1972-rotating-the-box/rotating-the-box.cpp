class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>>ans(n,vector<char>(m));
        for(int i = 0;i<m;i++){
            int blocked = n;
            for(int j = n-1;j>=0;j--){
                if(boxGrid[i][j]=='*'){
                    blocked = j;
                }
                else if(boxGrid[i][j]=='#'&&j!=blocked-1){
                    boxGrid[i][blocked-1] = boxGrid[i][j];
                    boxGrid[i][j] ='.';
                    blocked --;
                }
                else if(boxGrid[i][j]=='#'&&j==blocked-1){
                    blocked--;
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                ans[j][m-i-1] = boxGrid[i][j];
            }
        }
        return ans;
    }
};