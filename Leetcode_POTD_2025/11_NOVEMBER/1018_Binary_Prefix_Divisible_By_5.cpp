class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> truth_log;
        truth_log.reserve(nums.size());
        int phase_val = 0;
        for (int raw_bit : nums) {
            phase_val = ((phase_val << 1) | raw_bit) % 5;
            truth_log.push_back(phase_val == 0);
        }
        return truth_log;
    }
};
