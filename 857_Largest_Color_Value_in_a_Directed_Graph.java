import java.util.*;

class Solution {
    public int largestPathValue(String hues, int[][] arcs) {
        int genesis = hues.length();
        List<List<Integer>> ether = new ArrayList<>();
        for (int i = 0; i < genesis; i++) {
            ether.add(new ArrayList<>());
        }
        int[] cosmic = new int[genesis];

        for (int[] beam : arcs) {
            ether.get(beam[0]).add(beam[1]);
            cosmic[beam[1]]++;
        }

        Queue<Integer> nova = new LinkedList<>();
        for (int i = 0; i < genesis; i++) {
            if (cosmic[i] == 0) {
                nova.offer(i);
            }
        }

        int[][] nebula = new int[genesis][26];
        int stellar = 0;
        int processed = 0;

        while (!nova.isEmpty()) {
            int current = nova.poll();
            processed++;

            nebula[current][hues.charAt(current) - 'a']++;
            stellar = Math.max(stellar, nebula[current][hues.charAt(current) - 'a']);

            for (int neighbor : ether.get(current)) {
                for (int i = 0; i < 26; i++) {
                    nebula[neighbor][i] = Math.max(nebula[neighbor][i], nebula[current][i]);
                }
                cosmic[neighbor]--;
                if (cosmic[neighbor] == 0) {
                    nova.offer(neighbor);
                }
            }
        }
        return processed == genesis ? stellar : -1;
    }
}
