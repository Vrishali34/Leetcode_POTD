import java.util.*;

class Solution {
    public long minCost(int[] basket1, int[] basket2) {
        Map<Integer, Integer> overallCounts = new HashMap<>();
        long globalMinVal = Long.MAX_VALUE;

        for (int item : basket1) {
            overallCounts.put(item, overallCounts.getOrDefault(item, 0) + 1);
            globalMinVal = Math.min(globalMinVal, (long) item);
        }
        for (int item : basket2) {
            overallCounts.put(item, overallCounts.getOrDefault(item, 0) + 1);
            globalMinVal = Math.min(globalMinVal, (long) item);
        }

        for (int count : overallCounts.values()) {
            if (count % 2 != 0) {
                return -1;
            }
        }

        Map<Integer, Integer> b1Counts = new HashMap<>();
        for (int item : basket1) {
            b1Counts.put(item, b1Counts.getOrDefault(item, 0) + 1);
        }

        List<Integer> b1Excess = new ArrayList<>();
        List<Integer> b2Excess = new ArrayList<>();
        for (Map.Entry<Integer, Integer> entry : overallCounts.entrySet()) {
            int item = entry.getKey();
            int totalCount = entry.getValue();
            int targetCount = totalCount / 2;
            int b1Has = b1Counts.getOrDefault(item, 0);

            if (b1Has > targetCount) {
                for (int i = 0; i < b1Has - targetCount; i++) {
                    b1Excess.add(item);
                }
            } else if (b1Has < targetCount) {
                for (int i = 0; i < targetCount - b1Has; i++) {
                    b2Excess.add(item);
                }
            }
        }

        Collections.sort(b1Excess);
        Collections.sort(b2Excess, Collections.reverseOrder());

        long totalCost = 0;
        for (int i = 0; i < b1Excess.size(); i++) {
            long directSwapCost = Math.min((long)b1Excess.get(i), (long)b2Excess.get(i));
            totalCost += Math.min(directSwapCost, 2 * globalMinVal);
        }

        return totalCost;
    }
}
