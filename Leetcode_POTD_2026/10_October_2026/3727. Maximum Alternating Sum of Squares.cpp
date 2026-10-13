class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int total_count = nums.size();
        vector<long long> square_vals(total_count);
        for (int idx = 0; idx < total_count; idx++)
            square_vals[idx] = (long long)nums[idx] * nums[idx];

        sort(square_vals.rbegin(), square_vals.rend());

        int pos_slots = (total_count + 1) / 2;
        long long alt_score = 0;
        for (int pos = 0; pos < total_count; pos++)
            alt_score += (pos < pos_slots) ? square_vals[pos] : -square_vals[pos];

        return alt_score;
    }
};
