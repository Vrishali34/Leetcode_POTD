class Solution(object):
    def soupServings(self, n):
        if n >= 4800:
            return 1.0
        m = (n + 24) // 25
        memo = {}
        return self._calc_prob(m, m, memo)

    def _calc_prob(self, a, b, memo):
        if (a, b) in memo:
            return memo[(a, b)]
        if a <= 0 and b <= 0:
            return 0.5
        if a <= 0:
            return 1.0
        if b <= 0:
            return 0.0

        res = 0.25 * (self._calc_prob(a - 4, b, memo) +
                      self._calc_prob(a - 3, b - 1, memo) +
                      self._calc_prob(a - 2, b - 2, memo) +
                      self._calc_prob(a - 1, b - 3, memo))
        memo[(a, b)] = res
        return res
