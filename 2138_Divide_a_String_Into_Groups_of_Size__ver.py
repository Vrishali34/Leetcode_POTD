class Solution(object):
    def divideString(self, s, k, fill):
        """
        :type s: str
        :type k: int
        :type fill: str
        :rtype: List[str]
        """
        result = []
        # Calculate how many fill characters are needed for the last group
        # if the string length is not a multiple of k.
        # This uses the modulo operator to find the remainder,
        # and then subtracts from k to find how many fills are needed.
        # If remainder is 0, then (k - 0) % k will be 0, which is correct.
        padding_needed = (k - (len(s) % k)) % k
        
        # Append the necessary fill characters to the string
        s_padded = s + fill * padding_needed
        
        # Iterate through the padded string and create chunks of size k
        for i in range(0, len(s_padded), k):
            result.append(s_padded[i : i + k])
            
        return result
