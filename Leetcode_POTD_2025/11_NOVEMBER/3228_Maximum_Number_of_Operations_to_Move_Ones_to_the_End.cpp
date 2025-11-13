class Solution {
public:
    int maxOperations(string s) {
        int proton_count = 0, energy_released = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                proton_count++;
            } else if (i > 0 && s[i - 1] == '1') {
                energy_released += proton_count;
            }
        }
        return energy_released;
    }
};
