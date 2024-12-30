class Solution(object):
    def countGoodStrings(self, low, high, zero, one):
        BIGMOD = 10**9 + 7
        storage = [-1] * 100001
        
        def flux(l, h, z, o, cur):
            if cur > h:
                return 0
            if storage[cur] != -1:
                return storage[cur]
            count = 1 if l <= cur <= h else 0
            storage[cur] = (count + flux(l, h, z, o, cur + z) + flux(l, h, z, o, cur + o)) % BIGMOD
            return storage[cur]
        
        return flux(low, high, zero, one, 0)
