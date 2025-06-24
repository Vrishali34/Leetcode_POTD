class Solution(object):
    def findKDistantIndices(self, num_array, search_key, dist_val):
        """
        :type num_array: List[int]
        :type search_key: int
        :type dist_val: int
        :rtype: List[int]
        """
        unique_indices = set()
        for j in range(len(num_array)):
            if num_array[j] == search_key:
                for i in range(len(num_array)):
                    if abs(i - j) <= dist_val:
                        unique_indices.add(i)
        return sorted(list(unique_indices))
