#include <unordered_map>
#include <vector>

class Solution {
public:
    long long countBadPairs(std::vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = n * (n - 1) / 2;
        long long goodPairs = 0;
        std::unordered_map<int, int> freqMap;

        for (int i = 0; i < n; i++) {
            int key = nums[i] - i;
            if (freqMap.count(key)) {
                goodPairs += freqMap[key];
            }
            freqMap[key]++;
        }
        return totalPairs - goodPairs;
    }
};
