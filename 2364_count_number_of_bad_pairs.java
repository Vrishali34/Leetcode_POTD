import java.util.*;

class Solution {
    public long countBadPairs(int[] nums) {
        long n = nums.length;
        long totalPairs = n * (n - 1) / 2;
        long goodPairs = 0;
        Map<Integer, Integer> countMap = new HashMap<>();

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            goodPairs += countMap.getOrDefault(key, 0);
            countMap.put(key, countMap.getOrDefault(key, 0) + 1);
        }
        return totalPairs - goodPairs;
    }
}
