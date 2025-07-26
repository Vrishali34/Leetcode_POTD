import java.util.ArrayList;
import java.util.List;
import java.util.Collections; // For max/min operations, if not using Math.max/min

class Solution {
    public long maxSubarrays(int n, int[][] conflictingPairs) {
        // Pre-process conflicting pairs: map right endpoint to list of left endpoints
        List<List<Integer>> mysticSeals = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            mysticSeals.add(new ArrayList<>());
        }

        for (int[] sigil : conflictingPairs) {
            mysticSeals.get(Math.max(sigil[0], sigil[1])).add(Math.min(sigil[0], sigil[1]));
        }

        long totalLoreFragments = 0;
        long primeInhibitor = 0;
        long secondaryInhibitor = 0;

        long[] liberationScrolls = new long[n + 1]; // Using array for direct indexing

        // Sweep line from left to right (1 to n)
        for (int scryingPoint = 1; scryingPoint <= n; scryingPoint++) {
            for (int forbiddenOrigin : mysticSeals.get(scryingPoint)) {
                if (forbiddenOrigin > primeInhibitor) {
                    secondaryInhibitor = primeInhibitor;
                    primeInhibitor = forbiddenOrigin;
                } else if (forbiddenOrigin > secondaryInhibitor) {
                    secondaryInhibitor = forbiddenOrigin;
                }
            }
            
            // Calculate baseline valid subarrays for current scryingPoint
            totalLoreFragments += scryingPoint - primeInhibitor;
            
            // Accumulate potential gain if the primary inhibitor were removed
            if (primeInhibitor > 0) {
                liberationScrolls[(int)primeInhibitor] += primeInhibitor - secondaryInhibitor;
            }
        }

        // Find the maximum possible gain from removing one conflicting pair
        long maximumInsight = 0;
        for (long scroll : liberationScrolls) {
            maximumInsight = Math.max(maximumInsight, scroll);
        }

        // Return total baseline + maximum gain
        return totalLoreFragments + maximumInsight;
    }
}
