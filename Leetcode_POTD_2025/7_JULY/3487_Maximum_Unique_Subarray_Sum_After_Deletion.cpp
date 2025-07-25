class Solution {
public:
    int maxSum(std::vector<int>& celestial_glow) {
        std::set<int> collected_photons;
        int brightest_point = -200;
        for (int photon : celestial_glow) {
            if (photon >= 0) collected_photons.insert(photon);
            brightest_point = std::max(brightest_point, photon);
        }
        if (brightest_point < 0) return brightest_point;
        int total_luminosity = 0;
        for (int photon : collected_photons) total_luminosity += photon;
        return total_luminosity;
    }
};
