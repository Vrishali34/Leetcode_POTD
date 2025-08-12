 import math

class Solution(object):
    def numberOfWays(self, n, x):
        """
        :type n: int
        :type x: int
        :rtype: int
        """
        mod_prime = 1_000_000_007
        stellar_paths = [0] * (n + 1)
        stellar_paths[0] = 1

        star_masses = []
        i = 1
        while int(math.pow(i, x)) <= n:
            star_masses.append(int(math.pow(i, x)))
            i += 1

        for star in star_masses:
            for s in range(n, star - 1, -1):
                stellar_paths[s] = (stellar_paths[s] + stellar_paths[s - star]) % mod_prime
        
        return stellar_paths[n]
