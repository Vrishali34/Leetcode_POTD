import java.util.PriorityQueue;
import java.util.Collections;
import java.util.Arrays;

class Solution {
    public long minimumDifference(int[] nums) {
        int temporal_n = nums.length / 3;
        long[] bygone_min_sums = new long[nums.length];
        PriorityQueue<Integer> vault_min_heap = new PriorityQueue<>(Collections.reverseOrder()); // Max-heap for min sums
        long current_vault_sum = 0;

        for (int i = 0; i < 2 * temporal_n; ++i) {
            vault_min_heap.offer(nums[i]);
            current_vault_sum += nums[i];
            if (vault_min_heap.size() > temporal_n) {
                current_vault_sum -= vault_min_heap.poll();
            }
            if (vault_min_heap.size() == temporal_n) {
                bygone_min_sums[i] = current_vault_sum;
            }
        }

        long[] future_max_sums = new long[nums.length];
        PriorityQueue<Integer> abyss_max_heap = new PriorityQueue<>(); // Min-heap for max sums
        long current_abyss_sum = 0;

        for (int i = nums.length - 1; i >= temporal_n; --i) {
            abyss_max_heap.offer(nums[i]);
            current_abyss_sum += nums[i];
            if (abyss_max_heap.size() > temporal_n) {
                current_abyss_sum -= abyss_max_heap.poll();
            }
            if (abyss_max_heap.size() == temporal_n) {
                future_max_sums[i] = current_abyss_sum;
            }
        }

        long cosmic_delta = Long.MAX_VALUE;

        for (int k = temporal_n - 1; k < 2 * temporal_n; ++k) {
            // Check for valid states, as sums could be 0 if 'n' elements haven't been accumulated yet.
            // For example, if temporal_n is 1, bygone_min_sums[0] will be 0, but valid starts at index 0.
            // The condition `bygone_min_sums[k] != 0` is not strictly necessary if loop bounds are correct
            // and initialization defaults to 0 for `long` arrays. However, it mirrors the C++ logic.
            // A more robust check might involve ensuring 'k' and 'k+1' indices are within valid bounds
            // where `bygone_min_sums[k]` and `future_max_sums[k+1]` were actually populated.
            // Since the C++ version has `bygone_min_sums[k] != 0 && future_max_sums[k + 1] != 0`
            // and the arrays are initialized to 0, this implicitly checks if the sum was computed.
            // The bounds of `k` and `k+1` ensure we are always looking at valid indices where
            // the sums would have been populated.
            if (bygone_min_sums[k] != 0 && future_max_sums[k + 1] != 0) {
                cosmic_delta = Math.min(cosmic_delta, bygone_min_sums[k] - future_max_sums[k + 1]);
            }
        }
        return cosmic_delta;
    }
}
