class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int sz = nums.size();
        for (int p = 1; p < sz - 1; ++p) {
            for (int q = p + 1; q < sz - 1; ++q) {
                bool up_1 = true, down = true, up_2 = true;
                for (int i = 0; i < p; ++i) if (nums[i] >= nums[i+1]) up_1 = false;
                for (int i = p; i < q; ++i) if (nums[i] <= nums[i+1]) down = false;
                for (int i = q; i < sz - 1; ++i) if (nums[i] >= nums[i+1]) up_2 = false;
                if (up_1 && down && up_2) return true;
            }
        }
        return false;
    }
};
