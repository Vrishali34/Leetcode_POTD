import java.util.ArrayList;
import java.util.List;

class Solution {
    public long kMirror(int k, int n) {
        long sum = 0;
        int count = 0;
        
        // Iterate through possible lengths of the base-10 palindrome
        for (int len = 1; ; len++) {
            // Generate palindromes based on their first half
            // For example, if len = 3, first half can be 1, 2, ..., 9
            // If len = 4, first half can be 10, 11, ..., 99
            long startHalf = (long) Math.pow(10, (len - 1) / 2);
            long endHalf = (long) Math.pow(10, (len + 1) / 2);

            for (long i = startHalf; i < endHalf; i++) {
                String s = String.valueOf(i);
                StringBuilder sb = new StringBuilder(s);
                // Construct the palindrome
                // If len is odd, skip the middle digit of the first half (e.g., 121 from 12)
                // If len is even, append the reversed first half (e.g., 1221 from 12)
                String palindromeStr = s + sb.reverse().substring(len % 2);
                long num = Long.parseLong(palindromeStr);

                // Check if the number is a palindrome in base-k
                if (isPalindromeBaseK(num, k)) {
                    sum += num;
                    count++;
                    if (count == n) {
                        return sum;
                    }
                }
            }
        }
    }

    private boolean isPalindromeBaseK(long num, int k) {
        if (num == 0) return true; // Or handle based on problem definition for 0

        List<Integer> baseKDigits = new ArrayList<>();
        while (num > 0) {
            baseKDigits.add((int) (num % k));
            num /= k;
        }

        // Check if the base-k representation is a palindrome
        int left = 0;
        int right = baseKDigits.size() - 1;
        while (left < right) {
            if (!baseKDigits.get(left).equals(baseKDigits.get(right))) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
