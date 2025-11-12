import math
from functools import reduce

class Solution(object):
    
    def minOperations(self, nums):
        def _merge_matter(a, b):
            while b:
                a, b = b, a % b
            return a
        
        cosmos_len = len(nums)
        singularities = nums.count(1)
        
        if singularities > 0:
            return cosmos_len - singularities
        
        shortest_rift = float('inf')
        
        for outer_arc in range(cosmos_len):
            g_force = nums[outer_arc]
            for inner_arc in range(outer_arc + 1, cosmos_len):
                g_force = _merge_matter(g_force, nums[inner_arc])
                if g_force == 1:
                    shortest_rift = min(shortest_rift, inner_arc - outer_arc + 1)
                    break
        
        return shortest_rift + cosmos_len - 2 if shortest_rift != float('inf') else -1
