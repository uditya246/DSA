class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int k= 0;
        int sr = 0;
        int sc = 0;
        vector<int>row  = {-1,0,1,0};
        vector<int>col = {0,-1,0,1};
        vector<vector<int>>id(m,vector<int>(n,-1));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(classroom[i][j]=='S'){
                    sr = i;
                    sc = j;
                }
                if(classroom[i][j]=='L'){
                    id[i][j] = k++;
                }
            }
        }
        if(k==0) return 0;
        int totalmask = (1<<k) -1;
        vector<vector<vector<int>>>beste(m,vector<vector<int>>(n,vector<int>(1<<k,-1)));
        queue<array<int,5>>q;
        beste[sr][sc][0] = energy;
        q.push({sr,sc,0,energy,0});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(int ind = 0;ind<4;ind++){
                int nr = curr[0]+row[ind];
                int nc = curr[1] + col[ind];
                if(nr<0||nr>=m||nc<0||nc>=n){
                    continue;
                }
                if(classroom[nr][nc] =='X') continue;
                int ne = curr[3]-1;
                if(ne<0) continue;
                int nmask = curr[2];
                if(classroom[nr][nc]=='R') ne = energy;
                if(classroom[nr][nc]=='L'){
                    nmask |= (1<<id[nr][nc]);
                }
                if(nmask == totalmask) return curr[4]+1;
                if(ne <=beste[nr][nc][nmask]) continue;
                beste[nr][nc][nmask] = ne;
                q.push({nr,nc,nmask,ne,curr[4]+1});
            }
        }
        return -1;

    }
};