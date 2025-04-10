class Solution:
    def numberOfPowerfulInt(self, a: int, b: int, l: int, s: str) -> int:
        def z(x, y, d, m, t, p):
            if x < y: return 0
            x, r = divmod(x, t[d])
            i = next((j for j in range(17) if t[j] > x), 17)
            c = 0
            for j in range(i - 1, -1, -1):
                q, x = divmod(x, t[j])
                if q > m: return c + p[j + 1]
                c += p[j] * q
            return c + (r >= y)
        t = [10**i for i in range(17)]
        p = [(l + 1)**i for i in range(17)]
        y, d = int(s), len(s)
        return z(b, y, d, l, t, p) - z(a - 1, y, d, l, t, p)
