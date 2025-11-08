class Solution {
    public int minimumOneBitOperations(int epsilon_val) {
        if (epsilon_val == 0) {
            return 0;
        }
        
        int omega_bit = 1;
        while (omega_bit <= (epsilon_val >> 1)) {
            omega_bit <<= 1;
        }
        
        int omega_cost = (omega_bit << 1) - 1;
        int remainder = epsilon_val ^ omega_bit;
        
        return omega_cost - minimumOneBitOperations(remainder);
    }
}
