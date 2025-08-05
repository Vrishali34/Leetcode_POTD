class Solution(object):
    def numOfUnplacedFruits(self, fruits, baskets):
        """
        :type fruits: List[int]
        :type baskets: List[int]
        :rtype: int
        """
        r_c = 0
        p_b = [False] * len(baskets)
        for q_f in fruits:
            d_p = False
            for i in range(len(baskets)):
                if not p_b[i] and baskets[i] >= q_f:
                    p_b[i] = True
                    d_p = True
                    break
            if not d_p:
                r_c += 1
        return r_c
