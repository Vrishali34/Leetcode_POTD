class Solution {
public:
    int findKthNumber(int n, int k) {
        // 'prefVal' represents the current number we are considering in the lexicographical traversal.
        // We start with 1, the first number in the lexicographical sequence.
        long long prefVal = 1;

        // Decrement 'k' because we are looking for the k-th number, and our
        // traversal implicitly starts from the 1st number (prefVal = 1).
        --k;

        // Loop until 'k' becomes 0, meaning we have found our k-th number.
        while (k > 0) {
            // 'branches' will count the total numbers in the subtree rooted at 'prefVal * 10'
            // and all its subsequent sibling subtrees (e.g., if prefVal is 1, branches
            // would count 10, 11-19, 100-199, etc., up to 'n').
            long long branches = 0;

            // 'lLim' is the left boundary (inclusive) of the current range we are counting.
            // 'rLim' is the right boundary (exclusive) of the current range.
            // For example, if prefVal is 1, initially lLim=1, rLim=2.
            // In the first iteration of the inner loop, lLim will become 10, rLim will become 11, etc.
            long long lLim = prefVal, rLim = prefVal + 1;

            // This inner loop calculates the count of numbers under the current 'prefVal'
            // and its extended prefixes within the range [1, n].
            while (lLim <= n) {
                // Add the count of numbers in the current range [lLim, min(n, rLim-1)].
                // std::min((long long)n + 1, rLim) ensures we don't count beyond 'n'.
                // If rLim is 2 and lLim is 1, it counts 1.
                // If rLim is 11 and lLim is 10, it counts 10.
                branches += std::min((long long)n + 1, rLim) - lLim;

                // Optimization: if 'lLim' is already too large to form a 10x child without overflow
                // or exceeding 'n' by a factor of 10, we can stop early.
                if (lLim > n / 10) break;

                // Move to the next level in the lexicographical tree (e.g., from 1 to 10, 10 to 100).
                lLim *= 10;
                rLim *= 10;
            }

            // After counting 'branches', we decide whether the k-th number is within the
            // subtree rooted at 'prefVal * 10' (and its subsequent extensions) or
            // if we need to move to the next sibling (prefVal + 1).
            if (k >= branches) {
                // If 'k' is greater than or equal to 'branches', it means the k-th number
                // is NOT in the current branch's subtree. We "skip" this entire branch
                // and move to the next sibling of 'prefVal'.
                k -= branches;
                ++prefVal;
            } else {
                // If 'k' is less than 'branches', it means the k-th number IS within
                // the current branch's subtree. We "descend" into this subtree by
                // multiplying 'prefVal' by 10 (e.g., from 1 to 10, 2 to 20).
                // We also decrement 'k' because we've effectively moved past the current 'prefVal' itself.
                prefVal *= 10;
                --k;
            }
        }
        // Once 'k' becomes 0, 'prefVal' holds the k-th lexicographically smallest number.
        return prefVal;
    }
};
