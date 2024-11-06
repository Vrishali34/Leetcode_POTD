class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        bool ongoing = true;
        while (ongoing) {
            ongoing = false;
            for (int i = 1; i < nums.size(); i++) {
                if (__builtin_popcount(nums[i]) == __builtin_popcount(nums[i-1]) && nums[i-1] > nums[i]) {
                    swap(nums[i], nums[i-1]);
                    ongoing = true;
                }
            }
        }
        return is_sorted(nums.begin(), nums.end());
    }
};
