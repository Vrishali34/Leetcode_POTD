class Solution(object):
    def minCost(self, hues, chronos_cost):
        """
        :type colors: str
        :type neededTime: List[int]
        :rtype: int
        """
        aether_sum = 0
        peak_zephyr = 0
        for i in range(len(hues)):
            if i > 0 and hues[i] == hues[i-1]:
                aether_sum += min(peak_zephyr, chronos_cost[i])
                peak_zephyr = max(peak_zephyr, chronos_cost[i])
            else:
                peak_zephyr = chronos_cost[i]
        return aether_sum
