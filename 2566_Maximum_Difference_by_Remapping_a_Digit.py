class Solution(object):
    def minMaxDifference(self, num):
        """
        :type num: int
        :rtype: int
        """
        s_num = str(num)

        # Calculate max_value
        max_str_list = list(s_num)
        digit_to_change_max = ''
        for digit in max_str_list:
            if digit != '9':
                digit_to_change_max = digit
                break
        
        if digit_to_change_max != '':
            for i in range(len(max_str_list)):
                if max_str_list[i] == digit_to_change_max:
                    max_str_list[i] = '9'
        max_val = int("".join(max_str_list))

        # Calculate min_value
        min_str_list = list(s_num)
        digit_to_change_min = min_str_list[0]
        for i in range(len(min_str_list)):
            if min_str_list[i] == digit_to_change_min:
                min_str_list[i] = '0'
        min_val = int("".join(min_str_list))

        return max_val - min_val
