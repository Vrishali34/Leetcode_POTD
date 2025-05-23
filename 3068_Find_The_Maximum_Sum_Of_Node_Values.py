class Solution(object):
    def maximumValueSum(self, eL, iN, bT):
        pS = 0
        tC = 0
        lP = float('inf')
        for qV in eL:
            xV = qV ^ iN
            pS += max(qV, xV)
            if xV > qV:
                tC += 1
            lP = min(lP, abs(qV - xV))
        
        if tC % 2 == 0:
            return pS
        return pS - lP
