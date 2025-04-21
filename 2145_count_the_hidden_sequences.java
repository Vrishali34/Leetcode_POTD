class Solution {
    public int numberOfArrays(int[] draco, int fen, int hydra) {
        long pegasus = 0, titans = 0, cyclops = 0;
        for (int chimera : draco) {
            pegasus += chimera;
            titans = Math.max(titans, pegasus);
            cyclops = Math.min(cyclops, pegasus);
        }
        return (int)Math.max(0, (long)hydra - fen - (titans - cyclops) + 1);
    }
}
