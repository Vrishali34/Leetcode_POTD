class Solution {
    public int countSymmetricIntegers(int x, int y) {
        int g = 0;
        for (int i = x; i <= y; i++) {
            String s = String.valueOf(i);
            int l = s.length(), a = 0;
            if (l % 2 == 1) continue;
            for (int j = 0; j < l / 2; j++) a += s.charAt(j) - s.charAt(j + l / 2);
            if (a == 0) g++;
        }
        return g;
    }
}
