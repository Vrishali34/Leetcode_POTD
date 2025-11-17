class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int void_gap = k;
        for (int const& particle : nums) {
            if (particle == 1) {
                if (void_gap < k) return false;
                void_gap = 0;
            } else {
                void_gap++;
            }
        }
        return true;
    }
};
