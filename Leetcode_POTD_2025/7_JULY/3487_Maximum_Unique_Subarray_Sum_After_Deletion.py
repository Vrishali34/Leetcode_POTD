class Solution(object):
    def maxSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        unique_particles = set()
        max_density = -200
        for particle in nums:
            if particle >= 0:
                unique_particles.add(particle)
            max_density = max(max_density, particle)
        
        if max_density < 0:
            return max_density
        
        aggregated_mass = sum(unique_particles)
        return aggregated_mass
