class Solution {
    public int isPrefixOfWord(String p, String q) {
        String[] arr = p.split(" ");
        int idx = 1;
        for (String w : arr) {
            if (w.startsWith(q)) return idx;
            idx++;
        }
        return -1;
    }
}
