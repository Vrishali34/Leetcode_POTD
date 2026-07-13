class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> matchNums;
        string digitChain = "123456789";
        
        for (int spanLen = 2; spanLen <= 9; ++spanLen) {
            for (int startIdx = 0; startIdx <= 9 - spanLen; ++startIdx) {
                int evalNum = stoi(digitChain.substr(startIdx, spanLen));
                if (evalNum >= low && evalNum <= high) {
                    matchNums.push_back(evalNum);
                }
            }
        }
        return matchNums;
    }
};
