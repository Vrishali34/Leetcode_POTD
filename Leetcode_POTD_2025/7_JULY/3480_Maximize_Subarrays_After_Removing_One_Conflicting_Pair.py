class Solution(object):
    def maxSubarrays(self, n, conflictingPairs):
        """
        :type n: int
        :type conflictingPairs: List[List[int]]
        :rtype: int
        """
        # Pre-process conflicting pairs: map right endpoint to list of left endpoints
        mystic_seals = [[] for _ in range(n + 1)]
        for sigil in conflictingPairs:
            mystic_seals[max(sigil)].append(min(sigil))

        total_lore_fragments = 0
        prime_inhibitor = 0
        secondary_inhibitor = 0

        liberation_scrolls = [0] * (n + 1) # Using list as an array for direct indexing

        # Sweep line from left to right (1 to n)
        for scrying_point in range(1, n + 1):
            for forbidden_origin in mystic_seals[scrying_point]:
                if forbidden_origin > prime_inhibitor:
                    secondary_inhibitor = prime_inhibitor
                    prime_inhibitor = forbidden_origin
                elif forbidden_origin > secondary_inhibitor:
                    secondary_inhibitor = forbidden_origin
            
            # Calculate baseline valid subarrays for current scrying_point
            total_lore_fragments += scrying_point - prime_inhibitor
            
            # Accumulate potential gain if the primary inhibitor were removed
            if prime_inhibitor > 0:
                liberation_scrolls[int(prime_inhibitor)] += prime_inhibitor - secondary_inhibitor

        # Find the maximum possible gain from removing one conflicting pair
        maximum_insight = 0
        for scroll in liberation_scrolls:
            maximum_insight = max(maximum_insight, scroll)

        # Return total baseline + maximum gain
        return total_lore_fragments + maximum_insight
