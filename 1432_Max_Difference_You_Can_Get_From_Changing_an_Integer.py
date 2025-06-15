class Solution(object):
    def maxDiff(self, num):
        st_num = str(num)

        # Maximize
        max_val_list = list(st_num)
        repl_for_max = ''
        for char_m in max_val_list:
            if char_m != '9':
                repl_for_max = char_m
                break
        
        if repl_for_max == '':
            max_res = num
        else:
            max_res = int("".join(['9' if ch_m == repl_for_max else ch_m for ch_m in max_val_list]))

        # Minimize
        min_val_list = list(st_num)
        repl_for_min = ''
        
        if min_val_list[0] != '1':
            repl_for_min = min_val_list[0]
            min_res = int("".join(['1' if ch_min == repl_for_min else ch_min for ch_min in min_val_list]))
        else:
            for i_min in range(1, len(min_val_list)):
                if min_val_list[i_min] != '0' and min_val_list[i_min] != '1':
                    repl_for_min = min_val_list[i_min]
                    break
            if repl_for_min == '':
                min_res = num
            else:
                min_res = int("".join(['0' if ch_min == repl_for_min else ch_min for ch_min in min_val_list]))
        
        return max_res - min_res
