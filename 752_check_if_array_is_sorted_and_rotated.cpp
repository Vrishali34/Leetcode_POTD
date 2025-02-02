class Solution {
public:
    bool check(vector<int>& nums) {
        const int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > nums[(i + 1) % n] && ++count > 1) return false;
        }
        return true;
    }
};
