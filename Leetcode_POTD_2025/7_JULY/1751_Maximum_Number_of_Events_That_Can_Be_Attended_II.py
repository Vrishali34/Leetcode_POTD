import bisect

class Solution(object):
    def maxValue(self, events, k):
        """
        :type events: List[List[int]]
        :type k: int
        :rtype: int
        """
        # Sort events by their end days
        events.sort(key=lambda x: x[1])

        num_events = len(events)
        # dp_table[i][j] will store the maximum value attending up to j events
        # considering events from 0 to i-1 (inclusive)
        dp_table = [[0] * (k + 1) for _ in range(num_events + 1)]

        for i in range(1, num_events + 1):
            current_start_day = events[i - 1][0]
            current_value = events[i - 1][2]

            # Find the index of the latest non-overlapping event using binary search
            # We need to find an event `p` such that events[p][1] < current_start_day
            # Since events are sorted by end_day, we can use bisect_left to find the insertion point
            # for `current_start_day`. All events before this point might be non-overlapping.
            # We want the largest index `p` such that events[p][1] < current_start_day.
            
            # Create a list of end days for events considered so far (up to i-2) for binary search
            # This is less efficient than directly searching in `events` if we only compare the second element.
            # A more direct approach using `bisect_left` on the original `events` list with a custom key
            # or a manual binary search will be better.

            # Manual binary search is often clearer for this specific condition
            prev_event_idx = 0
            low_boundary, high_boundary = 0, i - 2 # Search in events from index 0 to i-2

            while low_boundary <= high_boundary:
                mid_point = low_boundary + (high_boundary - low_boundary) // 2
                if events[mid_point][1] < current_start_day:
                    prev_event_idx = mid_point + 1 # potential candidate, try for a later one
                    low_boundary = mid_point + 1
                else:
                    high_boundary = mid_point - 1 # this event overlaps or is too late
            
            for j in range(1, k + 1):
                # Option 1: Don't attend the current event (events[i-1])
                # Value comes from dp_table[i-1][j]
                
                # Option 2: Attend the current event (events[i-1])
                # Value is current_value + max value from attending j-1 events before prev_event_idx
                dp_table[i][j] = max(dp_table[i - 1][j], dp_table[prev_event_idx][j - 1] + current_value)
        
        return dp_table[num_events][k]
