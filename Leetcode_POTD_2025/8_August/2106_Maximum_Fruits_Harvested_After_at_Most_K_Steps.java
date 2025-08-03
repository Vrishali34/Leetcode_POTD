import java.util.Arrays;

class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        // --- Solution 1: Binary search with prefix sums ---
        // Create prefix sum array for efficient range sum queries
        int n = fruits.length;
        int[] prefix_sums = new int[n + 1];
        int[] positions = new int[n];
        for (int i = 0; i < n; i++) {
            prefix_sums[i + 1] = prefix_sums[i] + fruits[i][1];
            positions[i] = fruits[i][0];
        }

        int max_yield = 0;

        // Case 1: Move right, then turn and move left
        // 'r' is the distance moved to the right
        for (int r = 0; r <= k; r++) {
            // 'l_dist_needed' is the remaining steps to move left, after moving 2*r steps
            // (r steps right to the end, r steps back to start)
            int l_dist_needed = Math.max(0, k - 2 * r);
            int r_end_pos = startPos + r;
            int l_end_pos = startPos - l_dist_needed;
            
            // Find the indices of fruits within the reachable range [l_end_pos, r_end_pos]
            int r_idx = upperBound(positions, r_end_pos);
            int l_idx = lowerBound(positions, l_end_pos);
            
            max_yield = Math.max(max_yield, prefix_sums[r_idx] - prefix_sums[l_idx]);
        }
        
        // Case 2: Move left, then turn and move right
        // 'l' is the distance moved to the left
        for (int l = 0; l <= k; l++) {
            // 'r_dist_needed' is the remaining steps to move right
            int r_dist_needed = Math.max(0, k - 2 * l);
            int r_end_pos = startPos + r_dist_needed;
            int l_end_pos = startPos - l;
            
            // Find the indices and calculate fruit sum
            int r_idx = upperBound(positions, r_end_pos);
            int l_idx = lowerBound(positions, l_end_pos);
            
            max_yield = Math.max(max_yield, prefix_sums[r_idx] - prefix_sums[l_idx]);
        }
        
        return max_yield;
    }
    
    // Custom binary search to find the first element > value
    private int upperBound(int[] arr, int val) {
        int low = 0, high = arr.length;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > val) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    // Custom binary search to find the first element >= value
    private int lowerBound(int[] arr, int val) {
        int low = 0, high = arr.length;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= val) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
}

// --- Solution 2: Sliding Window ---
class Solution2 {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        // Create prefix sum array for O(1) range queries
        int n_fruits = fruits.length;
        int[] fruit_sums = new int[n_fruits + 1];
        for (int i = 0; i < n_fruits; i++) {
            fruit_sums[i + 1] = fruit_sums[i] + fruits[i][1];
        }
        
        int best_harvest = 0;
        int left_ptr = 0;
        
        // 'right_ptr' iterates through all fruits as the right endpoint of the window
        for (int right_ptr = 0; right_ptr < n_fruits; right_ptr++) {
            int right_fruit_pos = fruits[right_ptr][0];
            
            // Adjust the left pointer of the window
            // The total steps must be less than or equal to k
            while (left_ptr <= right_ptr) {
                int left_fruit_pos = fruits[left_ptr][0];
                int dist_to_right = Math.abs(right_fruit_pos - startPos);
                int dist_to_left = Math.abs(left_fruit_pos - startPos);

                // Calculate the total distance needed to cover the range [left_fruit_pos, right_fruit_pos]
                // and return to startPos
                int total_dist = dist_to_left + dist_to_right + Math.abs(left_fruit_pos - right_fruit_pos);

                if (total_dist > k + Math.min(dist_to_left, dist_to_right)) {
                    // If the distance is too large, shrink the window from the left
                    left_ptr++;
                } else {
                    // If the window is valid, break and calculate the fruits
                    break;
                }
            }
            
            // Calculate the total fruits in the current valid window [left_ptr, right_ptr]
            if (left_ptr <= right_ptr) {
                best_harvest = Math.max(best_harvest, fruit_sums[right_ptr + 1] - fruit_sums[left_ptr]);
            }
        }
        
        return best_harvest;
    }
}
