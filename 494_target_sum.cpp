class Solution {
public:
    int ewb(int m, vector<int>& n, int o, int p) {
        return m == p ? o == 0 : ewb(m + 1, n, o - n[m], p) + ewb(m + 1, n, o + n[m], p);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return ewb(0, nums, target, nums.size());
    }
};
