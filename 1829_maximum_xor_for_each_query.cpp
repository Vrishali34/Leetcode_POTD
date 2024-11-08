class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int mask=(1<<maximumBit)-1;
        for(int i=0, x=0; i<nums.size(); i++) x^=nums[i], nums[i]=x^mask;
        reverse(nums.begin(), nums.end());
        return nums;
    }
};
