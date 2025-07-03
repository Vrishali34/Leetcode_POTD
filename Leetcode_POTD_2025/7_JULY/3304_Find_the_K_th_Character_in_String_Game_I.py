class Solution(object):
    def kthCharacter(self, k):
        """
        :type k: int
        :rtype: str
        """
        current_len = 1
        prime_char = 'a'
        while k > current_len:
            current_len *= 2
        while current_len > 1:
            half_len = current_len // 2
            if k > half_len:
                k -= half_len
                prime_char = chr(((ord(prime_char) - ord('a') + 1) % 26) + ord('a'))
            current_len = half_len
        return prime_char
