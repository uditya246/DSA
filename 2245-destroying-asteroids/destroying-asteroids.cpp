class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long sum = mass;
        sort(asteroids.begin(),asteroids.end());
        if(sum>asteroids[n-1]) return true;
        if(sum<asteroids[0]) return false;
        sum +=asteroids[0];
        for(int i = 1;i<n;i++){
            if(sum<asteroids[i]) return false;
            sum+=asteroids[i];
        }
        return true;
    }
};