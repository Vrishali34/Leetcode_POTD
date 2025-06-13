class Solution {
public:
    int minimizeMax(std::vector<int>& nums, int p) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = nums[n - 1] - nums[0];
        int min_max_diff = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int pairs_count = 0;
            for (int i = 0; i < n - 1; ) {
                if (nums[i+1] - nums[i] <= mid) {
                    pairs_count++;
                    i += 2;
                } else {
                    i++;
                }
            }

            if (pairs_count >= p) {
                min_max_diff = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return min_max_diff;
    }
};
