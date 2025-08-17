class Solution(object):
    def new21Game(self, n, k, maxPts):
        if k == 0 or n >= k + maxPts:
            return 1.0
        
        dp = [0.0] * (n + 1)
        dp[0] = 1.0
        window_sum = 1.0
        result = 0.0
        
        for i in range(1, n + 1):
            dp[i] = window_sum / maxPts
            
            if i < k:
                window_sum += dp[i]
            
            if i >= maxPts:
                window_sum -= dp[i - maxPts]
            
            if i >= k:
                result += dp[i]
                
        return result
