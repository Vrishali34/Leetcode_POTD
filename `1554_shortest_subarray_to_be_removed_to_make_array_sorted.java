class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length, l = 0;
        while (l + 1 < n && arr[l] <= arr[l + 1]) l++;
        if (l == n - 1) return 0;
        int r = n - 1;
        while (r > l && arr[r - 1] <= arr[r]) r--;
        int minRem = Math.min(n - l - 1, r);
        for (int i = 0, j = r; i <= l && j < n;) {
            if (arr[i] <= arr[j]) {
                minRem = Math.min(minRem, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        return minRem;
    }
}
