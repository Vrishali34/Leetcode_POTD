class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long sum_all = 0, curr_f = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            sum_all += nums[i];
            curr_f += (long)i * nums[i];
        }
        long max_val = curr_f;
        for (int j = n - 1; j > 0; --j) {
            curr_f += sum_all - n * nums[j];
            max_val = max(max_val, curr_f);
        }
        return (int)max_val;
    }
};
