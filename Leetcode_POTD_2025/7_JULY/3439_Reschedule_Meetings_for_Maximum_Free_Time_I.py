class Solution(object):
    def maxFreeTime(self, univ_span, k_ops, begin_moments, end_moments):
        gap_sizes = []
        gap_sizes.append(begin_moments[0])
        for i in range(len(begin_moments) - 1):
            gap_sizes.append(begin_moments[i+1] - end_moments[i])
        gap_sizes.append(univ_span - end_moments[-1])

        max_period = 0
        current_sum = 0
        window_size = k_ops + 1

        for i in range(len(gap_sizes)):
            current_sum += gap_sizes[i]
            if i >= window_size - 1:
                max_period = max(max_period, current_sum)
                current_sum -= gap_sizes[i - (window_size - 1)]
        return max_period
