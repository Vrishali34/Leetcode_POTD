class Solution(object):
    def countOperations(self, alpha_val, beta_val):
        op_cycles = 0
        while alpha_val and beta_val:
            if alpha_val < beta_val:
                alpha_val, beta_val = beta_val, alpha_val
            
            jumps = alpha_val // beta_val
            op_cycles += jumps
            alpha_val %= beta_val
            
        return op_cycles
