class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        num_children = len(ratings)
        if num_children == 0:
            return 0

        # Initialize two arrays to store the potential candy counts
        # one for left-to-right consideration, and one for right-to-left.
        # Each child starts with at least one candy.
        left_candies = [1] * num_children
        right_candies = [1] * num_children

        # First independent pass: Left to right
        # Determine minimum candies based on the left neighbor's rating.
        for i in range(1, num_children):
            if ratings[i] > ratings[i - 1]:
                left_candies[i] = left_candies[i - 1] + 1

        # Second independent pass: Right to left
        # Determine minimum candies based on the right neighbor's rating.
        for i in range(num_children - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                right_candies[i] = right_candies[i + 1] + 1

        # Combine the results from both passes and sum them up.
        # The final candy count for each child is the maximum of what
        # they would need based on their left neighbor and what they
        # would need based on their right neighbor.
        total_candies = 0
        for i in range(num_children):
            total_candies += max(left_candies[i], right_candies[i])

        return total_candies
