class Solution {
public:
    double angleClock(int hour, int minutes) {
        double sol = abs((hour * 30) - (minutes * 11) / 2.0);
        return min(sol, 360-sol);
    }
};