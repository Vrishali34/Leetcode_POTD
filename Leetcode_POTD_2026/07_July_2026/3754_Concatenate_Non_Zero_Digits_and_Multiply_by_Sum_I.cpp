class Solution {
public:
    long long sumAndMultiply(int sourceVal) {
        long long extractedNum = 0;
        long long digitSum = 0;
        long long decimalPlace = 1;
        while (sourceVal > 0) {
            int currentDigit = sourceVal % 10;
            if (currentDigit != 0) {
                extractedNum += currentDigit * decimalPlace;
                digitSum += currentDigit;
                decimalPlace *= 10;
            }
            sourceVal /= 10;
        }
        return extractedNum * digitSum;
    }
};
