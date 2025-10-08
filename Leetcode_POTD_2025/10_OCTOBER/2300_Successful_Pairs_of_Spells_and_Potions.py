import bisect

class Solution(object):
    def successfulPairs(self, crystals, elixirs, goal):
        e_len = len(elixirs)
        elixirs.sort()
        results = []
        for c_val in crystals:
            min_p = (goal + c_val - 1) // c_val
            idx = bisect.bisect_left(elixirs, min_p)
            results.append(e_len - idx)
        return results
