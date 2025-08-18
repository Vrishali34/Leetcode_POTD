import math

class Solution(object):
    def judgePoint24(self, cards):
        """
        :type cards: List[int]
        :rtype: bool
        """
        cosmic_arr = [float(card) for card in cards]
        return self._cosmic_quest(cosmic_arr)

    def _cosmic_quest(self, realm):
        if len(realm) == 1:
            return abs(realm[0] - 24.0) < 1e-6

        for i in range(len(realm)):
            for j in range(i + 1, len(realm)):
                new_realms = [realm[k] for k in range(len(realm)) if k != i and k != j]

                temp_ops = [
                    realm[i] + realm[j],
                    realm[i] * realm[j],
                    realm[i] - realm[j],
                    realm[j] - realm[i],
                ]

                if realm[j] != 0:
                    temp_ops.append(realm[i] / realm[j])
                if realm[i] != 0:
                    temp_ops.append(realm[j] / realm[i])

                for val in temp_ops:
                    next_realm = new_realms + [val]
                    if self._cosmic_quest(next_realm):
                        return True
        return False
