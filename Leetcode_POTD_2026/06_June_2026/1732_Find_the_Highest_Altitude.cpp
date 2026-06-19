class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_alt = 0;
        int curr_alt = 0;
        for (int net_gain : gain) {
            curr_alt += net_gain;
            if (curr_alt > max_alt) max_alt = curr_alt;
        }
        return max_alt;
    }
};
