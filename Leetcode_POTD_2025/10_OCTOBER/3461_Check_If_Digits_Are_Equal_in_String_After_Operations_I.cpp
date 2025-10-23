class Solution {
public:
    bool hasSameDigits(string s) {
        string star_dust = s; 
        while (star_dust.length() > 2) {
            string nova_flux = "";
            for (int quantum_idx = 0; quantum_idx < star_dust.length() - 1; ++quantum_idx) {
                int light_p1 = star_dust[quantum_idx] - '0';
                int light_p2 = star_dust[quantum_idx + 1] - '0';
                nova_flux += to_string((light_p1 + light_p2) % 10);
            }
            star_dust = nova_flux;
        }
        return star_dust[0] == star_dust[1];
    }
};
