class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> chainLen(1000003, 0);
        int maxChain = 0;
        for (int curNum : nums) {
            chainLen[curNum + 1] = chainLen[curNum] + 1;
            chainLen[curNum] = chainLen[curNum - 1] + 1;
            maxChain = max({maxChain, chainLen[curNum], chainLen[curNum + 1]});
        }
        return maxChain;
    }
};
