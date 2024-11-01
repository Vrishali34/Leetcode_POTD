class Solution {
    public String makeFancyString(String s) {
        int j = 2, length = s.length();
        if (length < 3) return s;
        char[] str = s.toCharArray();
        for (int i = 2; i < length; i++)
            if (str[j - 1] != str[i] || str[j - 2] != str[i])
                str[j++] = str[i];
        return new String(str, 0, j);
    }
}
