class Solution {
public:
    int search(vector<int>& nums, int target) {
        int floor_idx = 0, roof_idx = nums.size() - 1;
        while (floor_idx <= roof_idx) {
            int mid_idx = floor_idx + (roof_idx - floor_idx) / 2;
            if (nums[mid_idx] == target) return mid_idx;
            if (nums[mid_idx] >= nums[floor_idx]) {
                if (target >= nums[floor_idx] && target < nums[mid_idx]) roof_idx = mid_idx - 1;
                else floor_idx = mid_idx + 1;
            } else {
                if (target > nums[mid_idx] && target <= nums[roof_idx]) floor_idx = mid_idx + 1;
                else roof_idx = mid_idx - 1;
            }
        }
        return -1;
    }
};
