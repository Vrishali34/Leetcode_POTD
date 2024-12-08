import java.util.*;

class Solution {
    public int maxTwoEvents(int[][] events) {
        int n = events.length, maxSum = 0;
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        int[] suffixMax = new int[n];
        suffixMax[n - 1] = events[n - 1][2];
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = Math.max(events[i][2], suffixMax[i + 1]);
        }
        for (int i = 0; i < n; ++i) {
            int left = i + 1, right = n - 1, nextIndex = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1]) {
                    nextIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if (nextIndex != -1) {
                maxSum = Math.max(maxSum, events[i][2] + suffixMax[nextIndex]);
            }
            maxSum = Math.max(maxSum, events[i][2]);
        }
        return maxSum;
    }
}
