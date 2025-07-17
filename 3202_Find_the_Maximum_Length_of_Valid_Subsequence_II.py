class Solution(object):
    def maximumLength(self, datum_arr, modulus_k):
        """
        :type datum_arr: List[int]
        :type modulus_k: int
        :rtype: int
        """
        zenith_len = 0
        for flux_val in range(modulus_k):
            epoch_track = [0] * modulus_k
            for num_val in datum_arr:
                curr_rem = num_val % modulus_k
                prev_rem = (modulus_k + flux_val - curr_rem) % modulus_k
                epoch_track[curr_rem] = max(epoch_track[curr_rem], epoch_track[prev_rem] + 1)
            for len_val in epoch_track:
                zenith_len = max(zenith_len, len_val)
        return zenith_len
