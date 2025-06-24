import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.TreeSet; // Using TreeSet for sorted unique elements

class Solution {
    public List<Integer> findKDistantIndices(int[] num_array, int search_key, int dist_val) {
        Set<Integer> unique_indices = new TreeSet<>();
        for (int j = 0; j < num_array.length; ++j) {
            if (num_array[j] == search_key) {
                for (int i = 0; i < num_array.length; ++i) {
                    if (Math.abs(i - j) <= dist_val) {
                        unique_indices.add(i);
                    }
                }
            }
        }
        return new ArrayList<>(unique_indices);
    }
}
