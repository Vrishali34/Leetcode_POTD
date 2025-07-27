class Solution(object):
    def countHillValley(self, nums):
        stellar_points = 0
        celestial_list = [nums[0]]
        for star_val in nums[1:]:
            if star_val != celestial_list[-1]:
                celestial_list.append(star_val)
        for i in range(1, len(celestial_list) - 1):
            if (celestial_list[i] > celestial_list[i-1] and celestial_list[i] > celestial_list[i+1]) or \
               (celestial_list[i] < celestial_list[i-1] and celestial_list[i] < celestial_list[i+1]):
                stellar_points += 1
        return stellar_points
