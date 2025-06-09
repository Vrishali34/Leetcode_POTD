class Solution {
    public int findKthNumber(int n, int k) {
        long prefVal = 1; // Current number we are considering in the lexicographical traversal
        k--; // Decrement k because we are looking for the k-th number, and our traversal implicitly starts from the 1st number (prefVal = 1).

        // Loop until k becomes 0, meaning we have found our k-th number.
        while (k > 0) {
            long branches = 0; // Counts total numbers in the subtree rooted at 'prefVal * 10' and its subsequent sibling subtrees.
            long lLim = prefVal; // Left boundary (inclusive) of the current range.
            long rLim = prefVal + 1; // Right boundary (exclusive) of the current range.

            // Calculates the count of numbers under the current 'prefVal' and its extended prefixes within the range [1, n].
            while (lLim <= n) {
                // Adds the count of numbers in the current range [lLim, min(n, rLim-1)].
                // Math.min((long)n + 1, rLim) ensures we don't count beyond 'n'.
                branches += Math.min((long)n + 1, rLim) - lLim;

                // Optimization: if 'lLim' is already too large to form a 10x child without
                // exceeding 'n', we can stop early to prevent overflow or unnecessary calculations.
                if (lLim > n / 10) break;

                // Move to the next level in the lexicographical tree (e.g., from 1 to 10, 10 to 100).
                lLim *= 10;
                rLim *= 10;
            }

            // After counting 'branches', decide whether the k-th number is within the
            // subtree rooted at 'prefVal * 10' (and its subsequent extensions) or
            // if we need to move to the next sibling (prefVal + 1).
            if (k >= branches) {
                // If 'k' is greater than or equal to 'branches', the k-th number
                // is NOT in the current branch's subtree. We "skip" this entire branch
                // and move to the next sibling of 'prefVal'.
                k -= branches;
                prefVal++;
            } else {
                // If 'k' is less than 'branches', the k-th number IS within
                // the current branch's subtree. We "descend" into this subtree by
                // multiplying 'prefVal' by 10 (e.g., from 1 to 10, 2 to 20).
                // We also decrement 'k' because we've effectively moved past the current 'prefVal' itself.
                prefVal *= 10;
                k--;
            }
        }
        // Once 'k' becomes 0, 'prefVal' holds the k-th lexicographically smallest number.
        return (int) prefVal;
    }
}
