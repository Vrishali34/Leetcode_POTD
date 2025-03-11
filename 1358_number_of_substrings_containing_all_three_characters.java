class Solution {
    public int numberOfSubstrings(String s) {
        int count = 0, left = 0;
        int[] freq = new int[3];

        for (char c : s.toCharArray()) {
            freq[c - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                freq[s.charAt(left++) - 'a']--;
            }

            count += left;
        }

        return count;
    }
}
