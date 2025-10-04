class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        void_max = 0
        left_a = 0
        right_b = len(height) - 1
        while left_a < right_b:
            pillar_a = height[left_a]
            pillar_b = height[right_b]
            width_x = right_b - left_a
            current_void = min(pillar_a, pillar_b) * width_x
            void_max = max(void_max, current_void)
            if pillar_a < pillar_b:
                left_a += 1
            else:
                right_b -= 1
        return void_max
