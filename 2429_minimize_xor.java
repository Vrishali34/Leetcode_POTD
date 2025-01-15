class Solution {
    public int minimizeXor(int num1, int num2) {
        int bitsNum2 = Integer.bitCount(num2);
        int bitsNum1 = Integer.bitCount(num1);
        while (bitsNum1 != bitsNum2) {
            num1 += (bitsNum1 < bitsNum2 ? 1 : -1);
            bitsNum1 = Integer.bitCount(num1);
        }
        return num1;
    }
}
