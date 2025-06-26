class Solution {
    public int longestSubsequence(String s, int k) {
        int currentBinarySum = 0;
        int countOfDigits = 0;
        int inputStringLength = s.length();

        for (int revIdx = inputStringLength - 1; revIdx >= 0; revIdx--) {
            if (s.charAt(revIdx) == '0') {
                countOfDigits++;
            } else {
                int bitPositionValue = 1 << (inputStringLength - 1 - revIdx);
                if (currentBinarySum + bitPositionValue <= k) {
                    currentBinarySum += bitPositionValue;
                    countOfDigits++;
                }
            }
        }
        return countOfDigits;
    }
}
