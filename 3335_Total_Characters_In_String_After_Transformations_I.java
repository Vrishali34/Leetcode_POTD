class Solution {
    public int lengthAfterTransformations(String s, int t) {
        final int M = 1000000007;
        long[] freq = new long[26];
        
        
        for (char c : s.toCharArray()) {
            freq[c - 'a']++;
        }

        
        while (t-- > 0) {
            long[] nextFreq = new long[26];
            for (int i = 0; i < 26; i++) {
                if (i == 25) {
                    nextFreq[0] = (nextFreq[0] + freq[i]) % M;
                    nextFreq[1] = (nextFreq[1] + freq[i]) % M;
                } else {
                    nextFreq[i + 1] = (nextFreq[i + 1] + freq[i]) % M;
                }
            }
            freq = nextFreq;
        }

        
        long result = 0;
        for (long count : freq) {
            result = (result + count) % M;
        }

        return (int) result;
    }
}
