class Solution(object):
    def maximumEnergy(self, energy, k):
        n_terms = len(energy)
        max_res = -float('inf')
        
        for t_idx in range(n_terms - 1, -1, -1):
            if t_idx + k < n_terms:
                energy[t_idx] += energy[t_idx + k]
            
            max_res = max(max_res, energy[t_idx])
            
        return max_res
