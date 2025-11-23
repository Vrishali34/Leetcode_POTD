class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> cosmic_state = {0, -20000000, -20000000};
        for (int nebula_particle : nums) {
            vector<int> next_flux = cosmic_state;
            for (int energy_level : cosmic_state) {
                if (energy_level == -20000000) continue;
                int potential_energy = energy_level + nebula_particle;
                next_flux[potential_energy % 3] = max(next_flux[potential_energy % 3], potential_energy);
            }
            cosmic_state = next_flux;
        }
        return cosmic_state[0];
    }
};
