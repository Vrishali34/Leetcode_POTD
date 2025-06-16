class Solution {
public:
    int maximumDifference(std::vector<int>& nums) {
        int max_diff = -1;
        int min_element = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > min_element) {
                max_diff = std::max(max_diff, nums[i] - min_element);
            }
            min_element = std::min(min_element, nums[i]);
        }
        return max_diff;
    }
};
