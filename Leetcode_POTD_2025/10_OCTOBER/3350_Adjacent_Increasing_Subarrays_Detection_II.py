class Solution(object):
    def find_max_duo_len(self, array_data):
        n_size = len(array_data)
        
        inc_end_len = [1] * n_size
        for i_c in range(1, n_size):
            if array_data[i_c - 1] < array_data[i_c]:
                inc_end_len[i_c] = inc_end_len[i_c - 1] + 1
        
        def is_feasible(k_len):
            if 2 * k_len > n_size:
                return False
            
            limit_a = n_size - 2 * k_len
            for start_a in range(limit_a + 1):
                
                end_idx_1 = start_a + k_len - 1
                if inc_end_len[end_idx_1] < k_len:
                    continue
                    
                end_idx_2 = start_a + 2 * k_len - 1
                if inc_end_len[end_idx_2] >= k_len:
                    return True
                    
            return False

        min_k, max_k, max_valid_k = 1, n_size // 2, 0
        
        while min_k <= max_k:
            curr_k = min_k + (max_k - min_k) // 2
            if is_feasible(curr_k):
                max_valid_k = curr_k
                min_k = curr_k + 1
            else:
                max_k = curr_k - 1
                
        return max_valid_k

    def maxIncreasingSubarrays(self, nums):
        return self.find_max_duo_len(nums)
