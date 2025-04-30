class Solution {
    public int findNumbers(int[] q) {
        int r = 0;
        for (int s : q) r += String.valueOf(s).length() % 2 == 0 ? 1 : 0;
        return r;
    }
}
