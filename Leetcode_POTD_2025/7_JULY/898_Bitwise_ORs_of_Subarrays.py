class Solution(object):
    def subarrayBitwiseORs(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        total_orns = set()
        ending_orns = set()
        for x in arr:
            next_ending_orns = {x}
            for y in ending_orns:
                next_ending_orns.add(x | y)
            ending_orns = next_ending_orns
            total_orns.update(ending_orns)
        return len(total_orns)
