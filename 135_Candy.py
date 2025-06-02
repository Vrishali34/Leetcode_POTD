class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        n = len(ratings)
        if n == 0:
            return 0

        # Initialize an array to store candies for each child.
        # Everyone starts with at least one candy.
        candies = [1] * n

        # First pass: Left to right
        # Ensure children with higher ratings than their left neighbor get more candies.
        for i in range(1, n):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1

        # Second pass: Right to left
        # Ensure children with higher ratings than their right neighbor get more candies.
        # This pass also combines with the previous pass's results.
        for i in range(n - 2, -1, -1):
            if ratings[i] > ratings[i + 1]:
                candies[i] = max(candies[i], candies[i + 1] + 1)

        # Sum up all the candies distributed.
        return sum(candies)
