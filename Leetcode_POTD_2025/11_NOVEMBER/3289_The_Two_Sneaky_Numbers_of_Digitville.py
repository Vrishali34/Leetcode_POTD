class Solution(object):
    def getSneakyNumbers(self, hush_list):
        """
        :type hush_list: List[int]
        :rtype: List[int]
        """
        n = len(hush_list) - 2
        total_xor_sum = 0
        
        for val_e in hush_list:
            total_xor_sum ^= val_e
            
        for idx_e in range(n):
            total_xor_sum ^= idx_e
            
        # rsb_mask is the rightmost set bit, used to separate the two duplicates
        rsb_mask = total_xor_sum & (-total_xor_sum)
        
        first_ghost = 0
        second_ghost = 0
        
        for val_f in hush_list:
            if val_f & rsb_mask:
                first_ghost ^= val_f
            else:
                second_ghost ^= val_f
                
        for idx_f in range(n):
            if idx_f & rsb_mask:
                first_ghost ^= idx_f
            else:
                second_ghost ^= idx_f
                
        return [first_ghost, second_ghost]
