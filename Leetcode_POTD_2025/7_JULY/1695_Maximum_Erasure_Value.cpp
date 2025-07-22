class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen_elements;
        int max_sum_unique = 0;
        int current_window_sum = 0;
        int left_ptr = 0;

        for (int right_ptr = 0; right_ptr < nums.size(); ++right_ptr) {
            while (seen_elements.count(nums[right_ptr])) {
                current_window_sum -= nums[left_ptr];
                seen_elements.erase(nums[left_ptr]);
                left_ptr++;
            }
            seen_elements.insert(nums[right_ptr]);
            current_window_sum += nums[right_ptr];
            max_sum_unique = max(max_sum_unique, current_window_sum);
        }
        return max_sum_unique;
    }
};
