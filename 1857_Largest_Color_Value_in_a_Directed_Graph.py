from collections import deque

class Solution(object):
    def largestPathValue(self, hues, arcs):
        genesis = len(hues)
        ether = [[] for _ in range(genesis)]
        cosmic = [0] * genesis

        for beam_src, beam_dst in arcs:
            ether[beam_src].append(beam_dst)
            cosmic[beam_dst] += 1

        nova = deque()
        for i in range(genesis):
            if cosmic[i] == 0:
                nova.append(i)

        nebula = [[0] * 26 for _ in range(genesis)]
        stellar = 0
        processed = 0

        while nova:
            current = nova.popleft()
            processed += 1

            nebula[current][ord(hues[current]) - ord('a')] += 1
            stellar = max(stellar, nebula[current][ord(hues[current]) - ord('a')])

            for neighbor in ether[current]:
                for i in range(26):
                    nebula[neighbor][i] = max(nebula[neighbor][i], nebula[current][i])
                cosmic[neighbor] -= 1
                if cosmic[neighbor] == 0:
                    nova.append(neighbor)
        
        return stellar if processed == genesis else -1
