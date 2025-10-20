class Solution(object):
    def finalValueAfterOperations(self, operations):
        n = len(operations)
        x = 0
        for i in range(n):
            
            found_plus = "+" in operations[i]
            
            if found_plus:
                x += 1
            else:
                x -= 1
        return x
