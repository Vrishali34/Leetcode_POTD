class Solution(object):
    def maxFreeTime(self, eventTime, startTime, endTime):
        """
        :type eventTime: int
        :type startTime: List[int]
        :type endTime: List[int]
        :rtype: int
        """
        n = len(startTime)
        p, q, mx = 0, startTime[0], 0
        h = [startTime[i] - endTime[i - 1] for i in range(1, n)]
        h.insert(0, q)
        h.append(eventTime - endTime[-1])

        suf = [0] * len(h)
        for i in range(len(h) - 2, -1, -1):
            suf[i] = max(suf[i + 1], h[i + 1])

        for i in range(1, len(h)):
            dur = endTime[i - 1] - startTime[i - 1]
            if dur <= max(p, suf[i]):
                mx = max(mx, h[i - 1] + h[i] + dur)
            mx = max(mx, h[i - 1] + h[i])
            p = max(p, h[i - 1])
        return mx
