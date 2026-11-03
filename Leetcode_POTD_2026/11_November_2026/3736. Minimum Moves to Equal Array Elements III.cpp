class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end()), moveCnt = 0;
        for (int num : nums) moveCnt += maxNum - num;
        return moveCnt;
    }
};
