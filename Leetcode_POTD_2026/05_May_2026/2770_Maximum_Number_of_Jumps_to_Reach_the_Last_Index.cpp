class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int sz = nums.size();
        vector<int> hop_count(sz, -1);
        hop_count[0] = 0;
        for (int curr = 1; curr < sz; ++curr) {
            for (int prev = 0; prev < curr; ++prev) {
                if (hop_count[prev] != -1 && abs(nums[curr] - nums[prev]) <= target) {
                    hop_count[curr] = max(hop_count[curr], hop_count[prev] + 1);
                }
            }
        }
        return hop_count[sz - 1];
    }
};
