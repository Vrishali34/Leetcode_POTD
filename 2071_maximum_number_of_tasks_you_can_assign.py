from bisect import bisect_left
from sortedcontainers import SortedList

class Solution:
    def maxTaskAssign(self, tasks, workers, pills, strength):
        tasks.sort()
        workers.sort()

        def can_do(k):
            wl = SortedList(workers[-k:])
            p = pills
            for i in range(k - 1, -1, -1):
                if wl[-1] >= tasks[i]:
                    wl.pop()
                else:
                    if p == 0:
                        return False
                    idx = wl.bisect_left(tasks[i] - strength)
                    if idx == len(wl):
                        return False
                    wl.pop(idx)
                    p -= 1
            return True

        l, r = 0, min(len(tasks), len(workers))
        res = 0
        while l <= r:
            m = (l + r) // 2
            if can_do(m):
                res = m
                l = m + 1
            else:
                r = m - 1
        return res
