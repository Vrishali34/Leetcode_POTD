class Solution {
public:
    int partitionArray(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int num_subsequences = 0;
        int i = 0;
        while (i < nums.size()) {
            num_subsequences++;
            int current_min = nums[i];
            while (i < nums.size() && nums[i] - current_min <= k) {
                i++;
            }
        }
        return num_subsequences;
    }
};
