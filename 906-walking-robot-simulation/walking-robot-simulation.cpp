class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int dir = 0;
        int ans = 0;
        set<pair<int,int>> blocked;
        for (auto &o : obstacles) {
            blocked.insert({o[0], o[1]});
        }
        vector<pair<int,int>> directions = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        for(int cmd : commands){
            if(cmd==-2){
                dir =(dir+3)%4;
            }
            else if(cmd==-1){
                dir = (dir+1)%4;
            }
            else{
                while(cmd--){
                    int nx = x+directions[dir].first;
                    int ny = y+directions[dir].second;
                    if(blocked.count({nx,ny})) break;
                    x = nx;
                    y = ny;
                    ans = max(ans,x*x+y*y);
                }
            }
        }
        return ans;
    }
};