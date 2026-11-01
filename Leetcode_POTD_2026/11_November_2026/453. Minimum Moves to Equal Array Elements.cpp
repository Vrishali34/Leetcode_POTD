class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minNum = *min_element(nums.begin(), nums.end());
        long long moveCnt = 0;
        for (int num : nums) moveCnt += num - minNum;
        return moveCnt;
    }
};
