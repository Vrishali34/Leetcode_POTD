class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long totalCount = 0;
        long currentStreak = 0;
        for (int num : nums) {
            if (num == 0) {
                currentStreak++;
                totalCount += currentStreak;
            } else {
                currentStreak = 0;
            }
        }
        return totalCount;
    }
}
