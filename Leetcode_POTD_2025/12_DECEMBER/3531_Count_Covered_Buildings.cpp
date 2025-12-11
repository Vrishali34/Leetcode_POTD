class Solution {
public:
    int countCoveredBuildings(int n_city, std::vector<std::vector<int>>& city_structures) {
        std::map<int, std::set<int>> col_coords;
        std::map<int, std::set<int>> row_coords;

        for (const auto& structure : city_structures) {
            col_coords[structure[0]].insert(structure[1]);
            row_coords[structure[1]].insert(structure[0]);
        }

        std::set<std::pair<int, int>> non_covered;
        
        for (const auto& pair : col_coords) {
            int x_coord = pair.first;
            non_covered.insert({x_coord, *pair.second.begin()});
            non_covered.insert({x_coord, *pair.second.rbegin()});
        }

        for (const auto& pair : row_coords) {
            int y_coord = pair.first;
            non_covered.insert({*pair.second.begin(), y_coord});
            non_covered.insert({*pair.second.rbegin(), y_coord});
        }

        return city_structures.size() - non_covered.size();
    }
};
