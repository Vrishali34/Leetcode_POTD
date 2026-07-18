class Solution {
public:
    int findGCD(vector<int>& nums) {
        int min_val = nums[0], max_val = nums[0];
        for (int num : nums) {
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }
        return __gcd(min_val, max_val);
    }
};
