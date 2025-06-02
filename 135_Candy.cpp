class Solution {
public:
    int candy(vector<int>& ratings) {
        // Get the number of children in the line.
        int plen = ratings.size();
        
        // If there are no children, no candies are needed.
        if (plen == 0) return 0;
        
        // Initialize a vector 'treats' to store the number of candies for each child.
        // Every child initially receives at least one candy.
        vector<int> treats(plen, 1);
        
        // --- Left to right pass ---
        // This pass ensures that a child with a higher rating than their left neighbor
        // receives more candies than that neighbor.
        for (int idx = 1; idx < plen; ++idx) {
            // If the current child's rating is greater than their left neighbor's rating,
            // they should receive one more candy than their left neighbor.
            if (ratings[idx] > ratings[idx-1]) {
                treats[idx] = treats[idx-1] + 1;
            }
        }
        
        // --- Right to left pass and sum ---
        // This pass ensures that a child with a higher rating than their right neighbor
        // receives more candies than that neighbor. It also calculates the total candies.
        
        // Initialize 'finalTreats' with the candies for the last child.
        // This is the starting point for summing up candies from right to left.
        int finalTreats = treats[plen-1];
        
        // Iterate from the second-to-last child back to the first child.
        for (int idx = plen - 2; idx >= 0; --idx) {
            // If the current child's rating is greater than their right neighbor's rating,
            // they *might* need more candies.
            if (ratings[idx] > ratings[idx+1]) {
                // We take the maximum of the candies already assigned (from the left-to-right pass)
                // and the candies required based on the right neighbor's rating plus one.
                // This handles cases where a child might have a higher rating than *both* neighbors.
                treats[idx] = std::max(treats[idx], treats[idx+1] + 1);
            }
            // Add the current child's determined candy count to the total.
            finalTreats += treats[idx];
        }
        
        // Return the total minimum number of candies required.
        return finalTreats;
    }
};
