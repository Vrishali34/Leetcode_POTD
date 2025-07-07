import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int maxEvents(int[][] events) {
        // Sort events by end day to prioritize earlier finishing events
        Arrays.sort(events, (a, b) -> a[1] - b[1]);

        // Use a Set to keep track of days attended
        Set<Integer> daysAttended = new HashSet<>();
        for (int[] event : events) {
            for (int day = event[0]; day <= event[1]; day++) {
                if (!daysAttended.contains(day)) {
                    daysAttended.add(day);
                    break;
                }
            }
        }
        return daysAttended.size();
    }
}
