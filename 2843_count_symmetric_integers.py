class Solution(object):
    def countSymmetricIntegers(self, l, r):
        return sum((lambda z: not len(z)%2 and sum(map(int,z[:len(z)//2]))==sum(map(int,z[len(z)//2:])))(str(i)) for i in range(l,r+1))
