class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        return count_if(nums.begin(), nums.end(), [](int cyber_shard) {
            return cyber_shard % 3 != 0;
        });
    }
};
