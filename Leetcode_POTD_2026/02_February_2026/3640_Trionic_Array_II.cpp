class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int span = nums.size();
        long long lowest = -2e18, best_fit = -2e18;
        vector<long long> rise_1(span, lowest), fall(span, lowest), rise_2(span, lowest);
        for (int idx = 1; idx < span; ++idx) {
            long long val = nums[idx], prev = nums[idx-1];
            if (val > prev) {
                rise_1[idx] = max((long long)prev, rise_1[idx-1]) + val;
                rise_2[idx] = max(fall[idx-1], rise_2[idx-1]) + val;
            } else if (val < prev) {
                fall[idx] = max(rise_1[idx-1], fall[idx-1]) + val;
            }
            best_fit = max(best_fit, rise_2[idx]);
        }
        return best_fit;
    }
};
