class Solution(object):
    def divideArray(self, nums, k):
        nums.sort()
        collection_of_triplets = []
        for i in range(0, len(nums), 3):
            if nums[i+2] - nums[i] > k:
                return []
            collection_of_triplets.append(nums[i:i+3])
        return collection_of_triplets
