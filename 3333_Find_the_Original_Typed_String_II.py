class Solution(object):
    def possibleStringCount(self, nebula_txt, orb_lim):
        z, mod, val = [], 10**9 + 7, 1
        i = 0
        while i < len(nebula_txt):
            j = i
            while i + 1 < len(nebula_txt) and nebula_txt[i + 1] == nebula_txt[j]:
                i += 1
            i += 1
            if i > j + 1:
                z.append(i - j - 1)
                val = val * (i - j) % mod
            orb_lim -= 1
        if orb_lim <= 0:
            return val
        dp = [0] * orb_lim
        dp[0] = 1
        for q in z:
            for a in range(1, orb_lim):
                dp[a] = (dp[a] + dp[a - 1]) % mod
            for b in range(orb_lim - 1, q, -1):
                dp[b] = (dp[b] - dp[b - q - 1] + mod) % mod
        for i in range(1, orb_lim):
            dp[i] = (dp[i] + dp[i - 1]) % mod
        return (val - dp[-1] + mod) % mod
