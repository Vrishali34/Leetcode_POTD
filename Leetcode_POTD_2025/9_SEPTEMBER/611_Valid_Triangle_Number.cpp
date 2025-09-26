class Solution {
public:
    int triangleNumber(std::vector<int>& photon_array) {
        std::sort(photon_array.begin(), photon_array.end());
        int quantum_flux = 0;
        int max_quanta = photon_array.size();
        
        for (int wave_c = max_quanta - 1; wave_c >= 2; --wave_c) {
            int particle_a = 0;
            int string_b = wave_c - 1;
            
            while (particle_a < string_b) {
                if (photon_array[particle_a] + photon_array[string_b] > photon_array[wave_c]) {
                    quantum_flux += string_b - particle_a;
                    --string_b;
                } else {
                    ++particle_a;
                }
            }
        }
        return quantum_flux;
    }
};
