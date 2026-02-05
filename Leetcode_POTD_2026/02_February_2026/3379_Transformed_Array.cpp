class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int span = nums.size();
        vector<int> shifted_res(span);
        for (int idx = 0; idx < span; ++idx) {
            int target_pos = ((idx + nums[idx]) % span + span) % span;
            shifted_res[idx] = nums[target_pos];
        }
        return shifted_res;
    }
};
