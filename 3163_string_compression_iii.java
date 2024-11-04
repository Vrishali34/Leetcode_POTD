class Solution {
    public String compressedString(String str) {
        int size = str.length(), start = 0;
        StringBuilder result = new StringBuilder(size);
        for (int end = 0; end < size; ) {
            while (end < size && str.charAt(end) == str.charAt(start)) end++;
            int q = (end - start) / 9, r = (end - start) % 9;
            for (int c = 0; c < q; c++) result.append("9").append(str.charAt(start));
            if (r > 0) result.append(r).append(str.charAt(start));
            start = end;
        }
        return result.toString();
    }
}
