class Solution:
    def recoverFromPreorder(self, s: str) -> TreeNode:
        stk, i = [], 0
        
        while i < len(s):
            d, v = 0, 0

            while i < len(s) and s[i] == '-':
                d += 1
                i += 1
            
            while i < len(s) and s[i].isdigit():
                v = v * 10 + int(s[i])
                i += 1

            n = TreeNode(v)

            if d == len(stk):
                if stk:
                    stk[-1].left = n
            else:
                stk[d - 1].right = n
                stk = stk[:d]
            
            stk.append(n)

        return stk[0]
