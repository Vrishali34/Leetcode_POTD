class Solution {
    public String longestSubsequenceRepeatedK(String s, int k) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) map.put(c, map.getOrDefault(c, 0) + 1);
        List<Character> usable = new ArrayList<>();
        for (char c = 'z'; c >= 'a'; c--) if (map.getOrDefault(c, 0) >= k) usable.add(c);

        Queue<String> q = new LinkedList<>();
        for (char c : usable) q.add("" + c);
        String out = "";

        while (!q.isEmpty()) {
            String now = q.poll();
            if (fit(s, now, k)) {
                if (now.length() > out.length() || (now.length() == out.length() && now.compareTo(out) > 0)) out = now;
                if (now.length() < 7) for (char c : usable) q.add(now + c);
            }
        }
        return out;
    }

    boolean fit(String s, String x, int k) {
        int i = 0, j = 0, rep = 0;
        while (i < s.length() && rep < k) {
            if (s.charAt(i) == x.charAt(j)) j++;
            if (j == x.length()) { rep++; j = 0; }
            i++;
        }
        return rep >= k;
    }
}
