class Solution {
public:
    double angleClock(int hour, int minutes) {
        int hr_units = (hour % 12) * 60 + minutes;
        int min_units = minutes * 12;
        double raw_gap = abs(hr_units - min_units) * 0.5;
        return raw_gap > 180.0 ? 360.0 - raw_gap : raw_gap;
    }
};
