class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourly = hour*30+(30.0/60)*minutes;
        double minutly = (360.0/60)*minutes;
        double ans = abs(hourly-minutly);
        if(ans>180) return 360-ans;
        return ans;
    }
};