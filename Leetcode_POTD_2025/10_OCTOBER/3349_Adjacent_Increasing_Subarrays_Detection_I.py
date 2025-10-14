class Solution(object):
    def hasIncreasingSubarrays(self, ancient_runes, wisdom_k):
        scroll_len = len(ancient_runes)
        search_limit = scroll_len - 2 * wisdom_k
        
        for base_idx in range(search_limit + 1):
            
            first_asc = True
            for i_1 in range(base_idx, base_idx + wisdom_k - 1):
                if ancient_runes[i_1] >= ancient_runes[i_1 + 1]:
                    first_asc = False
                    break
            
            if not first_asc:
                continue

            second_asc = True
            mid_idx = base_idx + wisdom_k
            for i_2 in range(mid_idx, mid_idx + wisdom_k - 1):
                if ancient_runes[i_2] >= ancient_runes[i_2 + 1]:
                    second_asc = False
                    break
            
            if second_asc:
                return True
                
        return False
