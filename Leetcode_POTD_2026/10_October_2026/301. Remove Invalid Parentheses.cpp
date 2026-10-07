class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> valid_results;
        unordered_set<string> visited_states;
        queue<string> bfs_queue;
        bfs_queue.push(s);
        visited_states.insert(s);
        bool found_at_level = false;

        auto is_valid_str = [](const string& candidate_str) {
            int bracket_bal = 0;
            for (char ch_val : candidate_str) {
                if (ch_val == '(') bracket_bal++;
                else if (ch_val == ')') bracket_bal--;
                if (bracket_bal < 0) return false;
            }
            return bracket_bal == 0;
        };

        while (!bfs_queue.empty()) {
            int level_size = bfs_queue.size();
            for (int idx = 0; idx < level_size; idx++) {
                string curr_str = bfs_queue.front(); bfs_queue.pop();
                if (is_valid_str(curr_str)) {
                    valid_results.push_back(curr_str);
                    found_at_level = true;
                }
                if (found_at_level) continue;
                for (int pos = 0; pos < (int)curr_str.size(); pos++) {
                    if (curr_str[pos] != '(' && curr_str[pos] != ')') continue;
                    string next_str = curr_str.substr(0, pos) + curr_str.substr(pos + 1);
                    if (visited_states.insert(next_str).second)
                        bfs_queue.push(next_str);
                }
            }
            if (found_at_level) break;
        }

        return valid_results;
    }
};
