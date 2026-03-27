class Solution(object):
    def areSimilar(self, mat, k):
        val_k = k % len(mat[0])
        for cur_row in mat:
            if cur_row != cur_row[val_k:] + cur_row[:val_k]:
                return False
        return True
