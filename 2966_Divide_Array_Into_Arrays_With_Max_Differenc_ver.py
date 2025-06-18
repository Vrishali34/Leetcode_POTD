class SolutionV2(object):
    def divideArray(self, nums, k):
        nums.sort()
        res_container = []
        for j in range(len(nums) // 3):
            sub_array_start_idx = j * 3
            if nums[sub_array_start_idx + 2] - nums[sub_array_start_idx] > k:
                return []
            res_container.append(nums[sub_array_start_idx : sub_array_start_idx + 3])
        return res_container
