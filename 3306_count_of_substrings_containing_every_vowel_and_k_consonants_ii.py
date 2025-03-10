class Solution(object):
    def countOfSubstrings(self, a, b):
        c, d, e, f, g, h = [[0] * 128 for _ in range(2)], 0, 0, 0, 0, 0
        for i in "aeiou": c[0][ord(i)] = 1
        for j in range(len(a)):
            k = ord(a[j])
            if c[0][k]: 
                c[1][k] += 1
                if c[1][k] == 1: 
                    e += 1
            else: 
                d += 1
            while d > b: 
                l = ord(a[g])  
                if c[0][l]: 
                    c[1][l] -= 1
                    if c[1][l] == 0: 
                        e -= 1
                else: 
                    d -= 1  
                g += 1  
                f = 0
            while e == 5 and d == b and g < j and c[0][ord(a[g])] and c[1][ord(a[g])] > 1: 
                f += 1
                c[1][ord(a[g])] -= 1
                g += 1
            if d == b and e == 5: 
                h += 1 + f
        return h
