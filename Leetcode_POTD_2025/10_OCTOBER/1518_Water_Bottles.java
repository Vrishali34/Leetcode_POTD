class Solution {
    public int numWaterBottles(int total_full, int swap_rate) {
        int drank_count = total_full;
        int empty_count = total_full;
        while (empty_count >= swap_rate) {
            int new_bottles = empty_count / swap_rate;
            drank_count += new_bottles;
            empty_count = (empty_count % swap_rate) + new_bottles;
        }
        return drank_count;
    }
}
