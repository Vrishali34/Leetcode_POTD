class Solution {
    public int maximum69Number (int num) {
        String numberAsString = String.valueOf(num);
        char[] digits = numberAsString.toCharArray();
        
        for (int i = 0; i < digits.length; i++) {
            if (digits[i] == '6') {
                digits[i] = '9';
                break;
            }
        }
        
        return Integer.parseInt(new String(digits));
    }
}
