class Solution {
    public int maxFreqSum(String s) {
        Map<Character, Integer> freqs = new HashMap<>();
        for (char ch : s.toCharArray()) {
            freqs.put(ch, freqs.getOrDefault(ch, 0) + 1);
        }
        int vMax = 0, cMax = 0;
        String vowels = "aeiou";
        for (Map.Entry<Character, Integer> entry : freqs.entrySet()) {
            char key = entry.getKey();
            int val = entry.getValue();
            if (vowels.indexOf(key) != -1) {
                vMax = Math.max(vMax, val);
            } else {
                cMax = Math.max(cMax, val);
            }
        }
        return vMax + cMax;
    }
}
