class Solution {
public:


    std::vector<int> lexicalOrder(int n) {
        std::vector<int> orderedNumbers;
        int currentDigit = 1;
        for (int i = 0; i < n; ++i) {
            orderedNumbers.push_back(currentDigit);
            if (currentDigit * 10 <= n) {
                currentDigit *= 10;
            } else {
                while (currentDigit % 10 == 9 || currentDigit + 1 > n) {
                    currentDigit /= 10;
                }
                currentDigit++;
            }
        }
        return orderedNumbers;
    }
};
