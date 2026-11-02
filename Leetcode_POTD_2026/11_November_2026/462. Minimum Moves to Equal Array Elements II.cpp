class Solution {
public:
int minMoves2(vector<int>& nums) {
        int midIdx = nums.size() / 2;
        nth_element(nums.begin(), nums.begin() + midIdx, nums.end());
        long long moveCnt = 0;
        for (int val : nums) moveCnt += abs((long long)val - nums[midIdx]);
        return moveCnt;
    }
};
