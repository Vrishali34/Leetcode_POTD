class Solution(object):
    def totalMoney(self, n):
        w_ct = n // 7
        d_rem = n % 7
        base_sum_w = 28
        
        sum_full = 7 * w_ct * (w_ct - 1) // 2 + base_sum_w * w_ct
        
        start_day_v = w_ct + 1
        sum_part = d_rem * start_day_v + d_rem * (d_rem - 1) // 2
        return sum_full + sum_part
