import java.util.HashMap;

class Solution {
    public int longestPalindrome(String[] words) {
        HashMap<String, Integer> chk = new HashMap<>();
        for (String w : words) {
            chk.put(w, chk.getOrDefault(w, 0) + 1);
        }

        int l = 0;
        boolean z = false;

        for (String wrd : chk.keySet()) {
            int cnt = chk.get(wrd);
            if (cnt == 0) continue; // Already processed

            if (wrd.charAt(0) == wrd.charAt(1)) {
                l += (cnt / 2) * 4;
                if (cnt % 2 == 1) {
                    z = true;
                }
            } else {
                String rev = "" + wrd.charAt(1) + wrd.charAt(0);
                if (chk.containsKey(rev)) {
                    int p = Math.min(cnt, chk.get(rev));
                    l += p * 4;
                    chk.put(wrd, 0); 
                    chk.put(rev, 0); 
                }
            }
        }
        return l + (z ? 2 : 0);
    }
}
