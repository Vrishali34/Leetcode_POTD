class Solution(object):
    def minimumRecolors(self, p, q):
        u = sum(map(lambda c: c == 'W', p[:q]))
        v = u
        for i in range(q, len(p)):
            u += (p[i] == 'W') - (p[i - q] == 'W')
            v = min(v, u)
        return v
