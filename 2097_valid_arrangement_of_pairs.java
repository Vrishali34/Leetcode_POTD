class Solution {
    public int[][] validArrangement(int[][] z) {
        Map<Integer, List<Integer>> a = new HashMap<>();
        Map<Integer, Integer> b = new HashMap<>(), c = new HashMap<>();
        for (int[] d : z) {
            a.computeIfAbsent(d[0], k -> new ArrayList<>()).add(d[1]);
            b.put(d[0], b.getOrDefault(d[0], 0) + 1);
            c.put(d[1], c.getOrDefault(d[1], 0) + 1);
        }
        int e = z[0][0];
        for (int f : a.keySet())
            if (b.getOrDefault(f, 0) > c.getOrDefault(f, 0)) {
                e = f;
                break;
            }
        Stack<Integer> g = new Stack<>();
        Deque<Integer> h = new ArrayDeque<>();
        g.push(e);
        while (!g.isEmpty()) {
            int i = g.peek();
            if (a.containsKey(i) && !a.get(i).isEmpty()) {
                g.push(a.get(i).remove(a.get(i).size() - 1));
            } else {
                h.addFirst(g.pop());
            }
        }
        int[][] j = new int[h.size() - 1][2];
        int k = h.pollFirst();
        int idx = 0;
        while (!h.isEmpty()) {
            j[idx++] = new int[] {k, h.peekFirst()};
            k = h.pollFirst();
        }
        return j;
    }
}
