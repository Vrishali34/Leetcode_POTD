import java.util.*;

class Solution {
    public long[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        long[] anubis = new long[n - k + 1];
        
        if (k <= x) {
            long current_sum = 0;
            for (int i = 0; i < n; i++) {
                current_sum += nums[i];
                if (i >= k) current_sum -= nums[i - k];
                if (i >= k - 1) anubis[i - k + 1] = current_sum;
            }
            return anubis;
        }

        Map<Integer, Integer> quanta = new HashMap<>();
        Comparator<Integer> axiom = (a, b) -> {
            int freq_a = quanta.getOrDefault(a, 0);
            int freq_b = quanta.getOrDefault(b, 0);
            if (freq_a != freq_b) return Integer.compare(freq_b, freq_a);
            return Integer.compare(b, a);
        };
        TreeSet<Integer> cosmos = new TreeSet<>(axiom);
        TreeSet<Integer> chaos = new TreeSet<>(axiom);
        long zephyr_sum = 0;

        for (int i = 0; i < n; i++) {
            int num_in = nums[i];
            int old_freq_in = quanta.getOrDefault(num_in, 0);
            if (old_freq_in > 0) {
                if (cosmos.remove(num_in)) zephyr_sum -= (long)num_in * old_freq_in;
                else chaos.remove(num_in);
            }
            quanta.put(num_in, old_freq_in + 1);
            chaos.add(num_in);

            if (i >= k) {
                int num_out = nums[i - k];
                int old_freq_out = quanta.get(num_out);
                if (cosmos.remove(num_out)) zephyr_sum -= (long)num_out * old_freq_out;
                else chaos.remove(num_out);
                
                int new_freq_out = old_freq_out - 1;
                if (new_freq_out == 0) quanta.remove(num_out);
                else {
                    quanta.put(num_out, new_freq_out);
                    chaos.add(num_out);
                }
            }

            while (cosmos.size() < x && !chaos.isEmpty()) {
                int genesis = chaos.pollFirst();
                cosmos.add(genesis);
                zephyr_sum += (long)genesis * quanta.get(genesis);
            }
            while (!cosmos.isEmpty() && !chaos.isEmpty()) {
                int omega = cosmos.last();
                int alpha = chaos.first();
                if (axiom.compare(omega, alpha) > 0) {
                    cosmos.remove(omega); chaos.add(omega);
                    zephyr_sum -= (long)omega * quanta.get(omega);
                    chaos.remove(alpha); cosmos.add(alpha);
                    zephyr_sum += (long)alpha * quanta.get(alpha);
                } else break;
            }

            if (i >= k - 1) {
                anubis[i - k + 1] = zephyr_sum;
            }
        }
        return anubis;
    }
}
