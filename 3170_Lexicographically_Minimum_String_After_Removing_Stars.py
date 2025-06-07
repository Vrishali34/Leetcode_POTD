import heapq

class Solution(object):
    def clearStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        char_indices_stack = [[] for _ in range(26)]
        char_priority_queue = []
        should_keep = [True] * len(s)

        for i, char_val in enumerate(s):
            if char_val == '*':
                smallest_char = heapq.heappop(char_priority_queue)
                last_idx = char_indices_stack[ord(smallest_char) - ord('a')].pop()
                
                should_keep[i] = False
                should_keep[last_idx] = False
            else:
                heapq.heappush(char_priority_queue, char_val)
                char_indices_stack[ord(char_val) - ord('a')].append(i)

        result = []
        for i in range(len(s)):
            if should_keep[i]:
                result.append(s[i])

        return "".join(result)
