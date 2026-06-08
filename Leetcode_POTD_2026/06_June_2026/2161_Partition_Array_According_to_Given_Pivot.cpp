class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> rearranged_arr(nums.size());
        int fill_idx = 0;
        for (int curr_val : nums) {
            if (curr_val < pivot) rearranged_arr[fill_idx++] = curr_val;
        }
        for (int curr_val : nums) {
            if (curr_val == pivot) rearranged_arr[fill_idx++] = curr_val;
        }
        for (int curr_val : nums) {
            if (curr_val > pivot) rearranged_arr[fill_idx++] = curr_val;
        }
        return rearranged_arr;
    }
};
