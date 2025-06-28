import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

class Solution {
    public int[] maxSubsequence(int[] quantum_states, int nexus_k) {
        Map<Integer, Integer> value_counts = new HashMap<>();
        PriorityQueue<Integer> lowest_values = new PriorityQueue<>(); 

        for (int val : quantum_states) {
            lowest_values.offer(val);
            if (lowest_values.size() > nexus_k) {
                lowest_values.poll();
            }
        }
        
        while (!lowest_values.isEmpty()) {
            int val = lowest_values.poll();
            value_counts.put(val, value_counts.getOrDefault(val, 0) + 1);
        }

        int[] chosen_sequence = new int[nexus_k];
        int current_idx = 0;
        for (int val : quantum_states) {
            if (current_idx < nexus_k && value_counts.getOrDefault(val, 0) > 0) {
                chosen_sequence[current_idx++] = val;
                value_counts.put(val, value_counts.get(val) - 1);
            }
        }
        return chosen_sequence;
    }
}
