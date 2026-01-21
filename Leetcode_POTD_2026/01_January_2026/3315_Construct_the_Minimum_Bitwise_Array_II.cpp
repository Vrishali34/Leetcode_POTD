class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> out_arr(nums.size());
        for (int idx = 0; idx < nums.size(); ++idx) {
            int prime_n = nums[idx];
            if (prime_n % 2 == 0) out_arr[idx] = -1;
            else {
                long bit_mask = 1;
                while (prime_n & bit_mask) bit_mask <<= 1;
                out_arr[idx] = prime_n ^ (bit_mask >> 1);
            }
        }
        return out_arr;
    }
};
