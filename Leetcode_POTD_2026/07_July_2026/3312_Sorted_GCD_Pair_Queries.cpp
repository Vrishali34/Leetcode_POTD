class Solution {
public:
    vector<int> gcdValues(vector<int>& itemsList, vector<long long>& indicesToSeek) {
        int highestVal = 0;
        for (int item : itemsList) highestVal = max(highestVal, item);
        
        vector<long long> elementTally(highestVal + 1, 0);
        for (int item : itemsList) elementTally[item]++;
        
        vector<long long> exactGcdCount(highestVal + 1, 0);
        for (int divisorCandidate = highestVal; divisorCandidate >= 1; --divisorCandidate) {
            long long multiplesFound = 0;
            for (int steppingVal = divisorCandidate; steppingVal <= highestVal; steppingVal += divisorCandidate) {
                multiplesFound += elementTally[steppingVal];
            }
            long long rawCombinations = (multiplesFound * (multiplesFound - 1)) / 2;
            for (int compositeVal = 2 * divisorCandidate; compositeVal <= highestVal; compositeVal += divisorCandidate) {
                rawCombinations -= exactGcdCount[compositeVal];
            }
            exactGcdCount[divisorCandidate] = rawCombinations;
        }
        
        for (int divisorCandidate = 1; divisorCandidate <= highestVal; ++divisorCandidate) {
            exactGcdCount[divisorCandidate] += exactGcdCount[divisorCandidate - 1];
        }
        
        vector<int> queryResolutions;
        queryResolutions.reserve(indicesToSeek.size());
        for (long long positionIdx : indicesToSeek) {
            auto searchPointer = upper_bound(exactGcdCount.begin(), exactGcdCount.end(), positionIdx);
            queryResolutions.push_back(distance(exactGcdCount.begin(), searchPointer));
        }
        return queryResolutions;
    }
};
