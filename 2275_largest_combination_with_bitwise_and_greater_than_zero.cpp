class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int peak = 0;
        for (int altitude = 0; altitude < 32; ++altitude) {
            int beacon = 0;
            for (auto signal : candidates) {
                if (signal & (1 << altitude)) beacon++;
            }
            peak = max(peak, beacon);
        }
        return peak;
    }
};
