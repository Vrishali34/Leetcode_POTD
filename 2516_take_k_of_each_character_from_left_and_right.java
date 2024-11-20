class Solution {
    public int takeCharacters(String s, int k) {
        int n = s.length(), l = 0, r = 0, minLen = n;
        int[] counts = new int[3];
        for (char c : s.toCharArray()) counts[c - 'a']++;
        if (counts[0] < k || counts[1] < k || counts[2] < k) return -1;
        for (; r < n; r++) {
            counts[s.charAt(r) - 'a']--;
            while (counts[0] < k || counts[1] < k || counts[2] < k)
                counts[s.charAt(l++) - 'a']++;
            minLen = Math.min(minLen, n - (r - l + 1));
        }
        return minLen;
    }
}
