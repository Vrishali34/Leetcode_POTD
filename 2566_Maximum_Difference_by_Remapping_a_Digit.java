class Solution {

    // Version 1: Standard approach
    public int minMaxDifference(int num) {
        String string_num = String.valueOf(num);
        char[] char_array_max = string_num.toCharArray();
        char digit_to_change_for_max = ' ';
        for (char c : char_array_max) {
            if (c != '9') {
                digit_to_change_for_max = c;
                break;
            }
        }
        if (digit_to_change_for_max != ' ') {
            for (int i = 0; i < char_array_max.length; i++) {
                if (char_array_max[i] == digit_to_change_for_max) {
                    char_array_max[i] = '9';
                }
            }
        }
        int max_val = Integer.parseInt(new String(char_array_max));

        char[] char_array_min = string_num.toCharArray();
        char digit_to_change_for_min = char_array_min[0];
        for (int i = 0; i < char_array_min.length; i++) {
            if (char_array_min[i] == digit_to_change_for_min) {
                char_array_min[i] = '0';
            }
        }
        int min_val = Integer.parseInt(new String(char_array_min));

        return max_val - min_val;
    }
}
