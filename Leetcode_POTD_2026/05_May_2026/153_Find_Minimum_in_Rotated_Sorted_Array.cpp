class Solution {
public:
    int findMin(vector<int>& nums) {
        int low_idx = 0;
        int high_idx = nums.size() - 1;
        while (low_idx < high_idx) {
            int mid_idx = low_idx + (high_idx - low_idx) / 2;
            if (nums[mid_idx] > nums[high_idx]) {
                low_idx = mid_idx + 1;
            } else {
                high_idx = mid_idx;
            }
        }
        return nums[low_idx];
    }
};
