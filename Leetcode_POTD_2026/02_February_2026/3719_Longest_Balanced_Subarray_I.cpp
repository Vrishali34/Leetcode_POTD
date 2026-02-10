class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int max_span = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            unordered_set<int> unique_evens, unique_odds;
            for (int j = i; j < n; ++j) {
                if (nums[j] % 2 == 0) unique_evens.insert(nums[j]);
                else unique_odds.insert(nums[j]);
                if (unique_evens.size() == unique_odds.size())
                    max_span = max(max_span, j - i + 1);
            }
        }
        return max_span;
    }
};
