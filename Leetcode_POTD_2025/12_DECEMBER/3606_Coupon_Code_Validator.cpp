class Solution {
    bool is_clean_id(const std::string& ident) {
        if (ident.empty()) return false;
        for (char c : ident) {
            if (!std::isalnum(c) && c != '_') return false;
        }
        return true;
    }

public:
    std::vector<std::string> validateCoupons(std::vector<std::string>& id_val, std::vector<std::string>& line_cat, std::vector<bool>& state_is_on) {
        std::map<int, std::vector<std::string>> valid_sorted_groups;
        std::unordered_map<std::string, int> cat_prio = {
            {"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}
        };
        int array_sz = id_val.size();

        for (int k = 0; k < array_sz; ++k) {
            const std::string& current_id = id_val[k];
            const std::string& current_cat = line_cat[k];
            bool current_state = state_is_on[k];

            if (current_state && cat_prio.count(current_cat) && is_clean_id(current_id)) {
                valid_sorted_groups[cat_prio[current_cat]].push_back(current_id);
            }
        }

        std::vector<std::string> final_result;
        for (auto& entry : valid_sorted_groups) {
            std::sort(entry.second.begin(), entry.second.end());
            final_result.insert(final_result.end(), entry.second.begin(), entry.second.end());
        }

        return final_result;
    }
};
