import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int maxValue(int[][] events, int k) {
        // Sort events by their end days
        Arrays.sort(events, Comparator.comparingInt(a -> a[1]));

        int numEvents = events.length;
        // dp_table[i][j] will store the maximum value attending up to j events
        // considering events from 0 to i-1 (inclusive)
        int[][] dpTable = new int[numEvents + 1][k + 1];

        for (int i = 1; i <= numEvents; ++i) {
            int currentStartDay = events[i - 1][0];
            int currentValue = events[i - 1][2];

            // Find the latest non-overlapping event using binary search
            // We need to find an event `p` such that events[p][1] < currentStartDay
            // Since events are sorted by end_day, we can use binary search on indices
            int prevEventIdx = 0;
            int lowBoundary = 0, highBoundary = i - 2; // Search in events before current

            while (lowBoundary <= highBoundary) {
                int midPoint = lowBoundary + (highBoundary - lowBoundary) / 2;
                if (events[midPoint][1] < currentStartDay) {
                    prevEventIdx = midPoint + 1; // potential candidate, try for a later one
                    lowBoundary = midPoint + 1;
                } else {
                    highBoundary = midPoint - 1; // this event overlaps or is too late
                }
            }

            for (int j = 1; j <= k; ++j) {
                // Option 1: Don't attend the current event (events[i-1])
                // Value comes from dpTable[i-1][j]
                
                // Option 2: Attend the current event (events[i-1])
                // Value is current_value + max value from attending j-1 events before prevEventIdx
                dpTable[i][j] = Math.max(dpTable[i - 1][j], dpTable[prevEventIdx][j - 1] + currentValue);
            }
        }
        return dpTable[numEvents][k];
    }
}
