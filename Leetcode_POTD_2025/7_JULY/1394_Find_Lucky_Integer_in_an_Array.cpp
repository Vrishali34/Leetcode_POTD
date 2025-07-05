class Solution {
public:
    int findLucky(std::vector<int>& arr) {
        std::unordered_map<int, int> aurora_borealis;
        for (int stellar_dust : arr) {
            aurora_borealis[stellar_dust]++;
        }
        int cosmic_echo = -1;
        for (auto const& [celestial_body, quantum_flux] : aurora_borealis) {
            if (celestial_body == quantum_flux) {
                cosmic_echo = std::max(cosmic_echo, celestial_body);
            }
        }
        return cosmic_echo;
    }
};
