class Solution(object):
    def longestPalindrome(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        bal = {}
        maxL = 0
        hasMid = False

        for str_val in words:
            revStr = str_val[1] + str_val[0]
            if bal.get(revStr, 0) > 0:
                maxL += 4
                bal[revStr] -= 1
                # If we used a self-palindromic word to form a pair, it can't be the center
                if str_val[0] == str_val[1]:
                    hasMid = False
            else:
                bal[str_val] = bal.get(str_val, 0) + 1
                # If we stored a self-palindromic word, it could be the center
                if str_val[0] == str_val[1]:
                    hasMid = True
        return maxL + (2 if hasMid else 0)
