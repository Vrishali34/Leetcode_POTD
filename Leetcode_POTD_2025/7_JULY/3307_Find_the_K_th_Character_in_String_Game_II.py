class Solution(object):
    def kthCharacter(self, k, operations): 
        prime_val = 'a'
        phase_shift = 0
        current_span = 1
        
        for _ in operations: 
            current_span <<= 1

        for morph_type in reversed(operations): 
            current_span >>= 1
            if k > current_span: 
                k -= current_span 
                if morph_type == 1:
                    phase_shift += 1
        
        final_char_code = ord(prime_val) + phase_shift
        return chr(ord('a') + (final_char_code - ord('a')) % 26)
