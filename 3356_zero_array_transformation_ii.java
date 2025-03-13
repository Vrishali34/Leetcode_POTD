class Solution {
    public int minZeroArray(int[] nums, int[][] queries) {
        int left = 0, right = queries.length, ans = -1;

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

    private boolean canZero(int[] nums, int[][] queries, int k) {
        int n = nums.length;
        int[] diff = new int[n + 1];
        int[] temp = nums.clone();

        for (int i = 0; i < k; i++) {
            diff[queries[i][0]] -= queries[i][2];
            diff[queries[i][1] + 1] += queries[i][2];
        }

        int curr = 0;
        for (int i = 0; i < n; i++) {
            curr += diff[i];
            if ((temp[i] += curr) > 0) return false;
        }
        return true;
    }
}
