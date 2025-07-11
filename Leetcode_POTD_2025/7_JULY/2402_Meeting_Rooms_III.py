import heapq

class Solution(object):
    def mostBooked(self, n, meetings):
        """
        :type n: int
        :type meetings: List[List[int]]
        :rtype: int
        """
        # Sort meetings by their start times
        meetings.sort()

        # Min-heap for available room numbers (void_pods)
        void_pods = []
        for i in range(n):
            heapq.heappush(void_pods, i)

        # Min-heap for occupied rooms (occupied_vessels)
        # Stores tuples of (meeting_end_time, room_number)
        occupied_vessels = []

        # List to count meetings per room (usage_tally)
        usage_tally = [0] * n

        for orbital_event in meetings:
            commencement_moment = orbital_event[0]
            termination_moment = orbital_event[1]

            # Release rooms where meetings have finished
            while occupied_vessels and occupied_vessels[0][0] <= commencement_moment:
                _, released_chamber = heapq.heappop(occupied_vessels)
                heapq.heappush(void_pods, released_chamber)

            # If a room is available, use the lowest numbered one
            if void_pods:
                chosen_chamber = heapq.heappop(void_pods)
                heapq.heappush(occupied_vessels, (termination_moment, chosen_chamber))
                usage_tally[chosen_chamber] += 1
            else:
                # If no rooms are free, delay the current meeting
                earliest_release_time, earliest_release_chamber = heapq.heappop(occupied_vessels)
                adjusted_end = earliest_release_time + (termination_moment - commencement_moment)
                heapq.heappush(occupied_vessels, (adjusted_end, earliest_release_chamber))
                usage_tally[earliest_release_chamber] += 1

        # Find the room with the most meetings
        pinnacle_chamber = 0
        for i in range(1, n):
            if usage_tally[i] > usage_tally[pinnacle_chamber]:
                pinnacle_chamber = i
        return pinnacle_chamber
