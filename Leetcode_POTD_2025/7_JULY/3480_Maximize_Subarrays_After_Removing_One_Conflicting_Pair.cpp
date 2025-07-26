#include <vector>
#include <algorithm>

class Solution {
public:
    long long maxSubarrays(int n, std::vector<std::vector<int>>& conflictingPairs) {
        std::vector<std::vector<int>> mysticSeals(n + 1);
        for (const auto& sigil : conflictingPairs) {
            mysticSeals[std::max(sigil[0], sigil[1])].push_back(std::min(sigil[0], sigil[1]));
        }

        long long totalLoreFragments = 0;
        long long primeInhibitor = 0;
        long long secondaryInhibitor = 0;

        std::vector<long long> liberationScrolls(n + 1, 0);

        for (int scryingPoint = 1; scryingPoint <= n; ++scryingPoint) {
            for (int forbiddenOrigin : mysticSeals[scryingPoint]) {
                if (forbiddenOrigin > primeInhibitor) {
                    secondaryInhibitor = primeInhibitor;
                    primeInhibitor = forbiddenOrigin;
                } else if (forbiddenOrigin > secondaryInhibitor) {
                    secondaryInhibitor = forbiddenOrigin;
                }
            }
            totalLoreFragments += scryingPoint - primeInhibitor;
            if (primeInhibitor > 0) {
                liberationScrolls[primeInhibitor] += primeInhibitor - secondaryInhibitor;
            }
        }
        
        long long maximumInsight = 0;
        for(long long scroll : liberationScrolls) {
            maximumInsight = std::max(maximumInsight, scroll);
        }

        return totalLoreFragments + maximumInsight;
    }
};
