class Solution(object):
    def removeOccurrences(self, a, b):
        q, n = [], len(b)
        for c in a:
            q.append(c)
            if len(q) >= n and "".join(q[-n:]) == b:
                del q[-n:]
        return "".join(q)
