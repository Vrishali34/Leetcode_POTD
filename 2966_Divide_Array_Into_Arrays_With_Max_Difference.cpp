#include <vector>
#include <algorithm> // Required for std::sort

class Solution {
public:
    std::vector<std::vector<int>> divideArray(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end()); // Sort the input array

        std::vector<std::vector<int>> collectionOfTriplets; // To store the resulting 2D array

        // Iterate through the sorted array, taking 3 elements at a time
        for (int i = 0; i < nums.size(); i += 3) {
            // Check the condition: difference between the third and first element must be <= k
            if (nums[i + 2] - nums[i] > k) {
                return {}; // Return an empty vector if the condition is not met
            }
            // Add the current triplet to the result
            collectionOfTriplets.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }

        return collectionOfTriplets; // Return the 2D array of triplets
    }
};
