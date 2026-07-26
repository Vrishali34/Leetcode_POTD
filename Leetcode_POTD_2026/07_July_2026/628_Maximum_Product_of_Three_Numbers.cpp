class Solution {
public:
    int maximumProduct(vector<int>& numSeq) {
        int maxValA = INT_MIN, maxValB = INT_MIN, maxValC = INT_MIN;
        int minValA = INT_MAX, minValB = INT_MAX;

        for (int curNum : numSeq) {
            if (curNum > maxValA) {
                maxValC = maxValB; maxValB = maxValA; maxValA = curNum;
            } else if (curNum > maxValB) {
                maxValC = maxValB; maxValB = curNum;
            } else if (curNum > maxValC) {
                maxValC = curNum;
            }

            if (curNum < minValA) {
                minValB = minValA; minValA = curNum;
            } else if (curNum < minValB) {
                minValB = curNum;
            }
        }
        return max(maxValA * maxValB * maxValC, maxValA * minValA * minValB);
    }
};
