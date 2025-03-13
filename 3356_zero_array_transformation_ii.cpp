class Solution {
public:
    bool canZero(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        vector<int> temp = nums;
        
        for (int i = 0; i < k; ++i) {
            diff[queries[i][0]] -= queries[i][2];
            diff[queries[i][1] + 1] += queries[i][2];
        }

        int curr = 0;
        for (int i = 0; i < n; ++i) {
            curr += diff[i];
            if ((temp[i] += curr) > 0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int left = 0, right = queries.size(), ans = -1;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canZero(nums, queries, mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
