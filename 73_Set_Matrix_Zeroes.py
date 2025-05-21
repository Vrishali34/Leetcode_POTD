class Solution(object):
    def setZeroes(self, M):
        R, C = len(M), len(M[0])
        fR = any(M[0][j]==0 for j in range(C))
        fC = any(M[i][0]==0 for i in range(R))
        for i in range(1,R):
            for j in range(1,C):
                if M[i][j]==0: M[i][0]=M[0][j]=0
        for i in range(1,R):
            for j in range(1,C):
                if M[i][0]==0 or M[0][j]==0: M[i][j]=0
        if fR: M[0]=[0]*C
        if fC:
            for i in range(R): M[i][0]=0
