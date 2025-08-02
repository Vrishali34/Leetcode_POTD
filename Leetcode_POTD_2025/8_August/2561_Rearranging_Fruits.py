import collections

class Solution(object):
    def minCost(self, basket1, basket2):
        """
        :type basket1: List[int]
        :type basket2: List[int]
        :rtype: int
        """
        
        # Hint 1 & 2: Create frequency maps and find the global minimum.
        # Check for odd total counts.
        overall_counts = collections.Counter(basket1) + collections.Counter(basket2)
        global_min_val = min(overall_counts.keys())
        
        for item in overall_counts:
            if overall_counts[item] % 2 != 0:
                return -1

        # Hint 3: Store excess items that need to be swapped.
        b1_counts = collections.Counter(basket1)
        b1_excess = []
        b2_excess = []

        for item in overall_counts:
            target_count = overall_counts[item] // 2
            b1_has = b1_counts.get(item, 0)
            
            if b1_has > target_count:
                for _ in range(b1_has - target_count):
                    b1_excess.append(item)
            elif b1_has < target_count:
                for _ in range(target_count - b1_has):
                    b2_excess.append(item)

        # Hint 4: Sort the lists for optimal pairing to minimize sum(min(a, b)).
        # One ascending, one descending.
        b1_excess.sort()
        b2_excess.sort(reverse=True)
        
        # Hint 5: Calculate the minimum cost of swapping.
        total_cost = 0
        for i in range(len(b1_excess)):
            item_a = b1_excess[i]
            item_b = b2_excess[i]
            
            # Cost of a direct swap
            direct_swap_cost = min(item_a, item_b)
            
            # Cost of an indirect swap using the global minimum
            indirect_swap_cost = 2 * global_min_val
            
            total_cost += min(direct_swap_cost, indirect_swap_cost)
            
        return total_cost
