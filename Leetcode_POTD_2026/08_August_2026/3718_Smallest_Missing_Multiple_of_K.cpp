class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> seen_vals(nums.begin(), nums.end());
        int cur_multiple = k;
        while (seen_vals.count(cur_multiple))
            cur_multiple += k;
        return cur_multiple;
    }
};
