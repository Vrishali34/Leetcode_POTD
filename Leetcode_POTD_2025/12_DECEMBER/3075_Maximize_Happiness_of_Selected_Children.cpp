class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long peak_joy = 0;
        int decay_step = 0;
        for (auto it = happiness.rbegin(); it != happiness.rbegin() + k; ++it) {
            peak_joy += max(0, *it - decay_step++);
        }
        return peak_joy;
    }
};
