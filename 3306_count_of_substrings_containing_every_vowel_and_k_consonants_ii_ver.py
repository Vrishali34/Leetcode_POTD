class Solution(object):
    def countOfSubstrings(self, w, z):
        y, x, v, u, t, s = [[0] * 128 for _ in range(2)], 0, 0, 0, 0, 0
        for r in "aeiou": y[0][ord(r)] = 1
        for q in range(len(w)):
            p = ord(w[q])
            if y[0][p]: 
                y[1][p] += 1
                if y[1][p] == 1: v += 1
            else: 
                x += 1
            while x > z: 
                o = ord(w[t])  
                if y[0][o]: 
                    y[1][o] -= 1
                    if y[1][o] == 0: v -= 1
                else: 
                    x -= 1  
                t += 1  
                u = 0
            while v == 5 and x == z and t < q and y[0][ord(w[t])] and y[1][ord(w[t])] > 1: 
                u += 1
                y[1][ord(w[t])] -= 1
                t += 1
            if x == z and v == 5: 
                s += 1 + u
        return s
