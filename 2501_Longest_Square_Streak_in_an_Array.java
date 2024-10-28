class Solution {
    private static final long LIMIT = 100001;
    public int longestSquareStreak(int[] elements) {
        BitSet exists = new BitSet((int)LIMIT);
        int highest = 0;
        for (int el : elements) {
            exists.set(el);
            highest = Math.max(highest, el);
        }
        int maxStreak = 0;
        for (long e : elements) {
            int streak = 1;
            for (long sq = e * e; sq <= highest; sq *= sq) {
                if (exists.get((int)sq)) streak++;
                else break;
            }
            maxStreak = Math.max(maxStreak, streak);
            if (maxStreak == 5) break;
        }
        return maxStreak < 2 ? -1 : maxStreak;
    }
}
