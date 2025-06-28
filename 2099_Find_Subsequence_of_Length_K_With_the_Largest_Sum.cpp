#include <vector>
#include <queue>
#include <algorithm>
#include <map>

class Solution {
public:
    std::vector<int> maxSubsequence(std::vector<int>& celestial_points, int orbital_count) {
        // Min-priority queue storing pairs of (value, original_index)
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>
            light_stream;

        for (int i = 0; i < celestial_points.size(); ++i) {
            light_stream.push({celestial_points[i], i});
            if (light_stream.size() > orbital_count) {
                light_stream.pop();
            }
        }

        std::vector<std::pair<int, int>> selected_stars;
        while (!light_stream.empty()) {
            selected_stars.push_back(light_stream.top());
            light_stream.pop();
        }

        // Sort by original index to maintain order
        std::sort(selected_stars.begin(), selected_stars.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });

        std::vector<int> resulting_flux;
        for (const auto& p : selected_stars) {
            resulting_flux.push_back(p.first);
        }
        return resulting_flux;
    }
};
