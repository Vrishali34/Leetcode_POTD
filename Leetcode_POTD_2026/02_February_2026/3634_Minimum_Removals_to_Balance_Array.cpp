class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int size_n = nums.size(), max_span = 0;
        for (int anchor = 0, lead = 0; lead < size_n; ++lead) {
            while ((long long)nums[lead] > (long long)nums[anchor] * k) anchor++;
            max_span = max(max_span, lead - anchor + 1);
        }
        return size_n - max_span;
    }
};
