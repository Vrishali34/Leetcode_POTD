import java.util.*;

class Solution {
    public int[] shortestDistanceAfterQueries(int a, int[][] b) {
        List<Integer> c = new ArrayList<>();
        int[] d = new int[a];
        List<List<Integer>> e = new ArrayList<>();
        for (int f = 0; f < a; f++) {
            d[f] = f;
            e.add(new ArrayList<>());
        }
        for (int f = 0; f < a - 1; f++) {
            e.get(f).add(f + 1);
        }
        for (int[] g : b) {
            int h = g[0], i = g[1];
            e.get(h).add(i);
            if (d[h] + 1 < d[i]) {
                Queue<Integer> j = new LinkedList<>();
                j.add(i);
                d[i] = d[h] + 1;
                while (!j.isEmpty()) {
                    int k = j.poll();
                    for (int l : e.get(k)) {
                        if (d[k] + 1 < d[l]) {
                            d[l] = d[k] + 1;
                            j.add(l);
                        }
                    }
                }
            }
            c.add(d[a - 1]);
        }
        return c.stream().mapToInt(x -> x).toArray();
    }
}
