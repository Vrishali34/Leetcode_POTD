class Solution(object):
    def findSmallestInteger(self, input_data, modulus_key):
        tally_array = [0] * modulus_key
        for item in input_data:
            tally_array[item % modulus_key] += 1
        
        max_chain = 0
        while tally_array[max_chain % modulus_key] > 0:
            tally_array[max_chain % modulus_key] -= 1
            max_chain += 1
            
        return max_chain
