class Solution(object):
    def maximum69Number (self, num):
        temp_num = num
        div = 1
        pos = -1

        while temp_num > 0:
            if temp_num % 10 == 6:
                pos = div
            
            temp_num //= 10
            div *= 10
        
        if pos != -1:
            return num + 3 * pos
        
        return num
