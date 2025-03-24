class Solution {
    public int countDays(int days, int[][] meets) {
        TreeMap<Integer, Integer> line = new TreeMap<>();
        for (int[] m : meets) {
            line.put(m[0], line.getOrDefault(m[0], 0) + 1);
            line.put(m[1] + 1, line.getOrDefault(m[1] + 1, 0) - 1);
        }
        int cnt = 0, prev = 1, free = 0;
        for (var e : line.entrySet()) {
            int curr = e.getKey(), delta = e.getValue();
            if (cnt == 0) free += curr - prev;
            cnt += delta;
            prev = curr;
        }
        if (prev <= days && cnt == 0) free += days - prev + 1;
        return free;
    }
}
