class Solution(object):
    def maxFrequency(self, nums, k, numOperations):
        optimum_span = 1
        partial_sum_limit = 0
        
        counts_map = {}
        all_points = set()
        sweep_map = {}

        for value in nums:
            counts_map[value] = counts_map.get(value, 0) + 1
            sweep_map[value - k] = sweep_map.get(value - k, 0) + 1
            sweep_map[value + k + 1] = sweep_map.get(value + k + 1, 0) - 1
            all_points.add(value)
            all_points.add(value - k)
            all_points.add(value + k + 1)

        for target_value in sorted(list(all_points)):
            partial_sum_limit += sweep_map.get(target_value, 0)
            
            initial_count = counts_map.get(target_value, 0)
            modified_count = partial_sum_limit - initial_count
            
            optimum_span = max(optimum_span, initial_count + min(modified_count, numOperations))
            
        return optimum_span
