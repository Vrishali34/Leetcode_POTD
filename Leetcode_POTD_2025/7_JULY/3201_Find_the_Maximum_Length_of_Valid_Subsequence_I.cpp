class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        int chron_even = 0;
        int chron_odd = 0;
        int weave_eo = 0;
        int weave_oe = 0;

        for (int temporal_slice : nums) {
            int time_distortion = temporal_slice % 2;
            if (time_distortion == 0) {
                chron_even++;
                weave_oe = weave_eo + 1;
            } else {
                chron_odd++;
                weave_eo = weave_oe + 1;
            }
        }
        return std::max({chron_even, chron_odd, weave_eo, weave_oe});
    }
};
