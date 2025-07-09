import java.util.ArrayList;
import java.util.List;

class Solution {
    public int maxFreeTime(int univ_span, int k_ops, int[] begin_moments, int[] end_moments) {
        List<Integer> gap_sizes = new ArrayList<>();
        gap_sizes.add(begin_moments[0]);
        for (int i = 0; i < begin_moments.length - 1; i++) {
            gap_sizes.add(begin_moments[i+1] - end_moments[i]);
        }
        gap_sizes.add(univ_span - end_moments[end_moments.length - 1]);

        int max_period = 0;
        int current_sum = 0;
        int window_size = k_ops + 1;

        for (int i = 0; i < gap_sizes.size(); i++) {
            current_sum += gap_sizes.get(i);
            if (i >= window_size - 1) {
                max_period = Math.max(max_period, current_sum);
                current_sum -= gap_sizes.get(i - (window_size - 1));
            }
        }
        return max_period;
    }
}
