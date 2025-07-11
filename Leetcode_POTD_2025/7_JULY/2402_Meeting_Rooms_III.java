import java.util.*;

class Solution {
    public int mostBooked(int n, int[][] meetings) {
        // Sort meetings by their start times
        Arrays.sort(meetings, (a, b) -> Integer.compare(a[0], b[0]));

        // Min-priority queue for available room numbers (void_pods)
        PriorityQueue<Integer> void_pods = new PriorityQueue<>();
        for (int i = 0; i < n; ++i) {
            void_pods.add(i);
        }

        // Min-priority queue for occupied rooms (occupied_vessels)
        // Stores pairs of {meeting_end_time, room_number}
        PriorityQueue<long[]> occupied_vessels = new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));

        // Array to count meetings per room (usage_tally)
        int[] usage_tally = new int[n];

        for (int[] orbital_event : meetings) {
            long commencement_moment = orbital_event[0];
            long termination_moment = orbital_event[1];

            // Release rooms where meetings have finished
            while (!occupied_vessels.isEmpty() && occupied_vessels.peek()[0] <= commencement_moment) {
                void_pods.add((int) occupied_vessels.poll()[1]);
            }

            // If a room is available, use the lowest numbered one
            if (!void_pods.isEmpty()) {
                int chosen_chamber = void_pods.poll();
                occupied_vessels.add(new long[]{termination_moment, chosen_chamber});
                usage_tally[chosen_chamber]++;
            } else {
                // If no rooms are free, delay the current meeting
                long[] earliest_release = occupied_vessels.poll();
                long adjusted_end = earliest_release[0] + (termination_moment - commencement_moment);
                occupied_vessels.add(new long[]{adjusted_end, earliest_release[1]});
                usage_tally[(int) earliest_release[1]]++;
            }
        }

        // Find the room with the most meetings
        int pinnacle_chamber = 0;
        for (int i = 1; i < n; ++i) {
            if (usage_tally[i] > usage_tally[pinnacle_chamber]) {
                pinnacle_chamber = i;
            }
        }
        return pinnacle_chamber;
    }
}
