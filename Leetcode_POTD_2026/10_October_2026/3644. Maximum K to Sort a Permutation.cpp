class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int and_val = -1;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i) and_val &= nums[i];
        return and_val == -1 ? 0 : and_val;
    }
};
