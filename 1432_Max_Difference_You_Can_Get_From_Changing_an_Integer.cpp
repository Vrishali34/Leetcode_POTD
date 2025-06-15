#include <string>
#include <algorithm>
#include <vector>

class Solution {
public:
    int maxDiff(int num) {
        std::string stNum = std::to_string(num);

        // Maximize
        std::string maxValStr = stNum;
        char replForMax = ' ';
        for (char charM : maxValStr) {
            if (charM != '9') {
                replForMax = charM;
                break;
            }
        }
        
        int maxRes;
        if (replForMax == ' ') {
            maxRes = num;
        } else {
            for (char &chM : maxValStr) {
                if (chM == replForMax) {
                    chM = '9';
                }
            }
            maxRes = std::stoi(maxValStr);
        }

        // Minimize
        std::string minValStr = stNum;
        char replForMin = ' ';
        
        int minRes;
        if (minValStr[0] != '1') {
            replForMin = minValStr[0];
            for (char &chMin : minValStr) {
                if (chMin == replForMin) {
                    chMin = '1';
                }
            }
            minRes = std::stoi(minValStr);
        } else {
            for (int iMin = 1; iMin < minValStr.length(); iMin++) {
                if (minValStr[iMin] != '0' && minValStr[iMin] != '1') {
                    replForMin = minValStr[iMin];
                    break;
                }
            }
            if (replForMin == ' ') {
                minRes = num;
            } else {
                for (char &chMin : minValStr) {
                    if (chMin == replForMin) {
                        chMin = '0';
                    }
                }
                minRes = std::stoi(minValStr);
            }
        }
        
        return maxRes - minRes;
    }
};
