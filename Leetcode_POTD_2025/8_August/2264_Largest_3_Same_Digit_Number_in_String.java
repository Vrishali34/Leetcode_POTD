class Solution {
    public String largestGoodInteger(String num) {
        for (int digit = 9; digit >= 0; digit--) {
            String triple = "" + digit + digit + digit;
            if (num.contains(triple)) {
                return triple;
            }
        }
        return "";
    }
}
