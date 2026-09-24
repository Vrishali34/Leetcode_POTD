class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for (int idx = 0; idx < nums.size(); idx++) {
            int val = nums[idx], digit_sum = 0;
            while (val > 0) {
                digit_sum += val % 10;
                val /= 10;
            }
            if (digit_sum == idx) return idx;
        }
        return -1;
    }
};
