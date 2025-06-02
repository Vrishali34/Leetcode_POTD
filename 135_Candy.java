class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        if (n == 0) {
            return 0;
        }

        // Initialize an array to store the candies for each child.
        // Everyone starts with at least one candy.
        int[] candies = new int[n];
        for (int i = 0; i < n; i++) {
            candies[i] = 1;
        }

        // First pass: Left to right
        // If a child has a higher rating than their left neighbor,
        // they get one more candy than their left neighbor.
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Second pass: Right to left
        // If a child has a higher rating than their right neighbor,
        // they must get more candies than their right neighbor.
        // We take the maximum of the current candy count and the one based on the right neighbor.
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = Math.max(candies[i], candies[i + 1] + 1);
            }
        }

        // Sum up all the candies.
        int totalCandies = 0;
        for (int i = 0; i < n; i++) {
            totalCandies += candies[i];
        }

        return totalCandies;
    }
}
