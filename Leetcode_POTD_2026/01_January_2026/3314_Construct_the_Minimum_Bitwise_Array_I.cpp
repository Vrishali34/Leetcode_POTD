class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> bit_res;
        for (int prime_val : nums) {
            int low_found = -1;
            for (int cand = 0; cand < prime_val; ++cand) {
                if ((cand | (cand + 1)) == prime_val) {
                    low_found = cand;
                    break;
                }
            }
            bit_res.push_back(low_found);
        }
        return bit_res;
    }
};
