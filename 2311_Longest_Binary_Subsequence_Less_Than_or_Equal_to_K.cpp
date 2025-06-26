class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long currentBinarySum = 0; // Use long long for currentBinarySum to prevent overflow during bit shifting
        int countOfDigits = 0;
        int inputStringLength = s.length();

        for (int revIdx = inputStringLength - 1; revIdx >= 0; revIdx--) {
            if (s[revIdx] == '0') {
                countOfDigits++;
            } else {
                // Calculate the bit position value using a long long literal for 1 to ensure the shift is done with a 64-bit integer
                long long bitPositionValue = 1LL << (inputStringLength - 1 - revIdx); 
                
                // Check if adding this bit would exceed k
                if (currentBinarySum + bitPositionValue <= k) {
                    currentBinarySum += bitPositionValue;
                    countOfDigits++;
                }
            }
        }
        return countOfDigits;
    }
};
