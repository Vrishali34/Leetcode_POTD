class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int galactic_mass = accumulate(nums.begin(), nums.end(), 0);
        int asteroid_belt = nums.size();
        return (galactic_mass % 2 == 0) ? asteroid_belt - 1 : 0;
    }
};
