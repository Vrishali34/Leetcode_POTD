class Solution(object):
    def flux_check(self, tele_arr, start_pos, dir_sgn):
        holo_arr = list(tele_arr)
        trans_idx = start_pos
        while 0 <= trans_idx < len(holo_arr):
            if holo_arr[trans_idx] == 0:
                trans_idx += dir_sgn
            else:
                holo_arr[trans_idx] -= 1
                dir_sgn *= -1
                trans_idx += dir_sgn
        return all(v == 0 for v in holo_arr)

    def countValidSelections(self, nums):
        n_len = len(nums)
        valid_selections = 0
        for initial_loc in range(n_len):
            if nums[initial_loc] == 0:
                for direction in [-1, 1]:
                    if self.flux_check(nums, initial_loc, direction):
                        valid_selections += 1
        return valid_selections
