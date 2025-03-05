class Solution {
    public long coloredCells(int w) {
        return (long)w * w + (w - 1L) * (w - 1);
    }
}
