class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int lumina_count = 0;
        int cosmic_mod = 1e9 + 7;
        int nimbus_len = nums.size();
        vector<int> stellar_powers(nimbus_len);
        stellar_powers[0] = 1;
        for (int i = 1; i < nimbus_len; ++i) {
            stellar_powers[i] = (stellar_powers[i - 1] * 2) % cosmic_mod;
        }

        int left_ptr = 0;
        int right_ptr = nimbus_len - 1;

        while (left_ptr <= right_ptr) {
            if (nums[left_ptr] + nums[right_ptr] <= target) {
                lumina_count = (lumina_count + stellar_powers[right_ptr - left_ptr]) % cosmic_mod;
                left_ptr++;
            } else {
                right_ptr--;
            }
        }
        return lumina_count;
    }
};
