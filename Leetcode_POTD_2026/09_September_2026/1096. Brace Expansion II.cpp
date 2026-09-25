class Solution {
public:
    int char_pos;
    string expr_str;

    set<string> parseUnion() {
        set<string> union_set = parseConcat();
        while (char_pos < expr_str.size() && expr_str[char_pos] == ',') {
            char_pos++;
            set<string> next_set = parseConcat();
            union_set.insert(next_set.begin(), next_set.end());
        }
        return union_set;
    }

    set<string> parseConcat() {
        vector<set<string>> term_list;
        while (char_pos < expr_str.size() && expr_str[char_pos] != ',' && expr_str[char_pos] != '}') {
            term_list.push_back(parseTerm());
        }

        set<string> concat_set = {""};
        for (auto& word_set : term_list) {
            set<string> merged_set;
            for (auto& prefix_word : concat_set)
                for (auto& suffix_word : word_set)
                    merged_set.insert(prefix_word + suffix_word);
            concat_set = merged_set;
        }
        return concat_set;
    }

    set<string> parseTerm() {
        if (expr_str[char_pos] == '{') {
            char_pos++;
            set<string> inner_set = parseUnion();
            char_pos++;
            return inner_set;
        } else {
            return {string(1, expr_str[char_pos++])};
        }
    }

    vector<string> braceExpansionII(string expression) {
        expr_str = expression;
        char_pos = 0;
        set<string> result_set = parseUnion();
        return vector<string>(result_set.begin(), result_set.end());
    }
};
