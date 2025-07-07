import heapq

class Solution(object):
    def maxEvents(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """
        events.sort(key=lambda x: x[1])

        attended_days = set()
        for start, end in events:
            for day in range(start, end + 1):
                if day not in attended_days:
                    attended_days.add(day)
                    break
        return len(attended_days)
