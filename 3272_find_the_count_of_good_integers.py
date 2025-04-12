class Solution(object):
    def countGoodIntegers(self, n, k):
        from math import factorial
        seen, res = set(), 0
        half = (n + 1) // 2
        lo, hi = 10**(half - 1), 10**half

        for i in range(lo, hi):
            s = str(i)
            pal = s + s[-2::-1] if n % 2 else s + s[::-1]
            if int(pal) % k != 0:
                continue
            sig = ''.join(sorted(pal))
            if sig in seen:
                continue
            seen.add(sig)
            freq = [pal.count(str(d)) for d in range(10)]

            total = factorial(n)
            for f in freq:
                total //= factorial(f)

            # Now remove invalid permutations with leading zero
            bad = 0
            if freq[0] > 0:
                freq[0] -= 1
                bad = factorial(n - 1)
                for f in freq:
                    bad //= factorial(f)
                freq[0] += 1
            res += total - bad

        return res
