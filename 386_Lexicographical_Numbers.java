import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> orderedNumbers = new ArrayList<>();
        int currentDigit = 1;
        for (int i = 0; i < n; ++i) {
            orderedNumbers.add(currentDigit);
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
}
