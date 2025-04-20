class Solution(object):
    def numRabbits(self, answers):
        from collections import defaultdict
        groups = defaultdict(list)
        total = 0

        for ans in answers:
            placed = False
            for i in range(len(groups[ans])):
                if groups[ans][i] < ans + 1:
                    groups[ans][i] += 1
                    placed = True
                    break
            if not placed:
                groups[ans].append(1)
                total += ans + 1

        return total
