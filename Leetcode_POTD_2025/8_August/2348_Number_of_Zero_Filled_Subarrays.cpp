class Solution {
public:
    long long zeroFilledSubarray(std::vector<int>& nums) {
        long long total_count = 0;
        long long current_streak = 0;
        for (int num : nums) {
            if (num == 0) {
                current_streak++;
                total_count += current_streak;
            } else {
                current_streak = 0;
            }
        }
        return total_count;
    }
};
