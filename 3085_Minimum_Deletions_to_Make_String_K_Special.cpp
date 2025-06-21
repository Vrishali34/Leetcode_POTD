#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <climits>

class Solution {
public:
    int minimumDeletions(std::string word, int k) {
        std::map<char, int> freqMap;
        for (char c : word) {
            freqMap[c]++;
        }

        std::set<int> uniqueFreqsSet;
        for (auto const& [key, val] : freqMap) {
            uniqueFreqsSet.insert(val);
        }

        std::vector<int> uniqueFreqs(uniqueFreqsSet.begin(), uniqueFreqsSet.end());
        std::sort(uniqueFreqs.begin(), uniqueFreqs.end());

        int minDeletions = INT_MAX;

        for (int lowFreqTarget : uniqueFreqs) {
            int currentDeletions = 0;
            for (auto const& [key, charFreq] : freqMap) {
                if (charFreq < lowFreqTarget) {
                    currentDeletions += charFreq;
                } else if (charFreq > lowFreqTarget + k) {
                    currentDeletions += charFreq - (lowFreqTarget + k);
                }
            }
            minDeletions = std::min(minDeletions, currentDeletions);
        }
        
        return minDeletions;
    }
};
