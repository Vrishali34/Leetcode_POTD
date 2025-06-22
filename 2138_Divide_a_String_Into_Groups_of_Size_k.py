class Solution(object):
    def divideString(self, s, k, fill):
        """
        :type s: str
        :type k: int
        :type fill: str
        :rtype: List[str]
        """
        groups = []
        n = len(s)
        for i in range(0, n, k):
            current_group = s[i:i + k]
            if len(current_group) < k:
                current_group += fill * (k - len(current_group))
            groups.append(current_group)
        return groups
