#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
    int stellar_census(vector<int>::iterator nebula_start, vector<int>::iterator nebula_end, int core_limit) {
        unordered_map<int, int> star_masses;
        int total_energy = 0;
        for (auto it = nebula_start; it != nebula_end; ++it) {
            star_masses[*it]++;
            total_energy += *it;
        }

        if (star_masses.size() <= core_limit) return total_energy;

        vector<pair<int, int>> celestial_bodies;
        for (auto const& [val, freq] : star_masses) celestial_bodies.push_back({freq, val});

        sort(celestial_bodies.begin(), celestial_bodies.end(), [](const auto& a, const auto& b) {
            return a.first != b.first ? a.first > b.first : a.second > b.second;
        });

        unordered_set<int> galactic_core;
        for (int i = 0; i < core_limit; ++i) galactic_core.insert(celestial_bodies[i].second);

        int core_energy = 0;
        for (auto it = nebula_start; it != nebula_end; ++it) {
            if (galactic_core.count(*it)) core_energy += *it;
        }
        return core_energy;
    }

public:
    vector<int> findXSum(vector<int>& space_dust, int scope_width, int top_x_quanta) {
        vector<int> constellations;
        int n = space_dust.size();
        for (int i = 0; i <= n - scope_width; ++i) {
            constellations.push_back(stellar_census(space_dust.begin() + i, space_dust.begin() + i + scope_width, top_x_quanta));
        }
        return constellations;
    }
};
