import java.util.Arrays;

class Solution {

    // Helper to count elements <= value (equivalent to std::upper_bound in C++)
    // Returns the count of elements that are less than or equal to 'val'
    private int countLE(int[] arr, long val) {
        int low = 0;
        int high = arr.length - 1;
        int count = 0; // This will be the index of the first element > val

        while (low <= high) {
            int mid_idx = low + (high - low) / 2;
            if (arr[mid_idx] <= val) {
                count = mid_idx + 1; // All elements up to mid_idx are <= val
                low = mid_idx + 1;
            } else {
                high = mid_idx - 1;
            }
        }
        return count;
    }

    // Helper to count elements >= value (equivalent to std::lower_bound in C++)
    // Returns the index of the first element that is greater than or equal to 'val'
    private int countGEIndex(int[] arr, long val) {
        int low = 0;
        int high = arr.length - 1;
        int index = arr.length; // Default to arr.length if no element is >= val

        while (low <= high) {
            int mid_idx = low + (high - low) / 2;
            if (arr[mid_idx] >= val) {
                index = mid_idx;
                high = mid_idx - 1;
            } else {
                low = mid_idx + 1;
            }
        }
        return index;
    }

    public long kthSmallestProduct(int[] nums1, int[] nums2, long k) {
        long low = -100_000_000_00L; 
        long high = 100_000_000_00L;  
        long ans = 0;

        while (low <= high) {
            long mid_product_candidate = low + (high - low) / 2;
            long current_product_count = 0;

            for (int n1 : nums1) {
                if (n1 == 0) {
                    if (mid_product_candidate >= 0) {
                        current_product_count += nums2.length;
                    }
                } else if (n1 > 0) {
                    // We need n1 * n2 <= mid_product_candidate  =>  n2 <= mid_product_candidate / n1
                    // This requires floor division
                    long target_n2_val = floorDiv(mid_product_candidate, n1);
                    current_product_count += countLE(nums2, target_n2_val);

                } else { // n1 < 0
                    // We need n1 * n2 <= mid_product_candidate  =>  n2 >= mid_product_candidate / n1 (inequality flips)
                    // This requires ceil division
                    long target_n2_val = ceilDiv(mid_product_candidate, n1);
                    current_product_count += (nums2.length - countGEIndex(nums2, target_n2_val));
                }
            }

            if (current_product_count >= k) {
                ans = mid_product_candidate;
                high = mid_product_candidate - 1;
            } else {
                low = mid_product_candidate + 1;
            }
        }
        return ans;
    }

    // Helper for floor division
    private long floorDiv(long dividend, int divisor) {
        long result = dividend / divisor;
        // Adjust if negative and not perfectly divisible
        if (dividend < 0 && dividend % divisor != 0 && (dividend < 0) != (divisor < 0)) { // Different signs
            result--;
        }
        return result;
    }

    // Helper for ceil division
    private long ceilDiv(long dividend, int divisor) {
        long result = dividend / divisor;
        // Adjust if positive and not perfectly divisible
        // Or if negative and not perfectly divisible and same signs
        if (dividend % divisor != 0 && (dividend < 0) == (divisor < 0)) { // Same signs
            result++;
        }
        return result;
    }
}
