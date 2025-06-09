class Solution(object):
    def findKthNumber(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        pref_val = 1
        k -= 1  # Decrement k as we're looking for the k-th number, and we start counting from 1.

        while k > 0:
            branches = 0
            l_lim, r_lim = pref_val, pref_val + 1

            while l_lim <= n:
                # Count numbers in the current range [l_lim, min(n, r_lim - 1)]
                branches += min(n + 1, r_lim) - l_lim

                # Optimization: if l_lim is already too large to form a 10x child
                # without exceeding n, we can stop early.
                if l_lim > n // 10:
                    break

                l_lim *= 10
                r_lim *= 10
            
            if k >= branches:
                # If k is greater than or equal to 'branches', it means the k-th number
                # is NOT in the current branch's subtree. Skip this entire branch
                # and move to the next sibling of 'pref_val'.
                k -= branches
                pref_val += 1
            else:
                # If k is less than 'branches', the k-th number IS within
                # the current branch's subtree. Descend into this subtree.
                # Decrement k because we've effectively moved past the current 'pref_val' itself.
                pref_val *= 10
                k -= 1
        
        return pref_val
